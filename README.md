# ExamHolder (آزمون‌یار)

A console exam system in C++. Professors write exams made of three different
kinds of question, enrol students and mark their answers; students sit those
exams against a countdown and collect their grades.

Written as second-semester object-oriented programming coursework in spring
2021. The first commit here is that original code, unchanged. Everything after
it is repair work — see [Provenance](#provenance) at the end.

---

## Contents

- [Building and running](#building-and-running)
- [A session](#a-session)
- [What each role can do](#what-each-role-can-do)
- [Design](#design)
- [The data model](#the-data-model)
- [Source layout](#source-layout)
- [Limitations](#limitations)
- [Glossary](#glossary)
- [Provenance](#provenance)

---

## Building and running

Open `ExamHolder.sln` in Visual Studio 2019 or later and build. The project
targets the v142 toolset; Visual Studio 2022 offers to retarget it to v143,
which is fine.

It also builds from the command line with no project file:

```
g++ -std=c++17 -Wall -Wextra -o ExamHolder main.cpp io.cpp professor.cpp soal.cpp student.cpp
```

There are no third-party dependencies. The program is Windows-only in one
respect: it clears the screen with `system("cls")`. It compiles and runs
elsewhere, but the screen will not clear.

Everything lives in memory. Closing the program discards all accounts, exams
and grades — see [Limitations](#limitations).

## A session

Registration and login come first; the main menu offers both for each role.
Once logged in, a professor builds an exam — a name, a duration in minutes,
then questions and a roster.

A student sitting that exam sees one question at a time, with the clock:

```
soal 1 az 2   |   zaman baqimande: 90 daqiqe va 0 sanie
-------------------------------------------------------
What is 2 plus 2?
1. three
2. four
3. five
4. six

pasokh -> four
```

Their answers become a sheet, which is what the professor is shown when
marking:

```
daneshjooye mored nazar ra entekhab konid:
1. Sara Ahmadi

->1) four
2) Because of gravity

nomre ra vared konid:
->18
```

The grade then appears on the student's own screen, and in the professor's
history for that exam.

## What each role can do

**A professor can:**

| | |
|---|---|
| `ijad azmoon` | create an exam: name, duration, questions, enrolled students |
| `tarikhche` | review a past exam — every enrolled student with their grade, or a note that they have none yet |
| `modiriyat` | rename an exam, change its duration, enrol more students, add more questions |
| `tashih` | mark an exam: pick from the students not yet graded, read the answer sheet, enter a number |

Enrolling a student who has no account creates one for them, so a professor can
build a roster before anyone has registered.

**A student can:**

| | |
|---|---|
| `moroor azmoon ha` | list the exams they are enrolled in |
| `dadan azmoon` | sit an exam |
| `nomarat` | see their grade for each exam, once entered |

Sitting an exam shows each question in turn through its own `show()`, records an
answer for each, and stores the finished sheet. The remaining time is displayed
above every question; when it runs out the exam ends and any questions not
reached are recorded unanswered. An exam can be sat only once — the listing
marks the ones already submitted.

## Design

**Questions are a polymorphic hierarchy.** `soal` is abstract: it holds the
question text and declares a pure virtual `show()`. Three subclasses implement
it, each rendering itself in the way its type requires:

| Class | Renders as |
|---|---|
| `soal_gozine` | the question plus four numbered options |
| `soal_truefalse` | the question plus a true/false pair |
| `soal_tashrihi` | the question alone, for a written answer |

An exam holds `vector<unique_ptr<soal>>`, so it stores the base type and calls
`show()` without knowing which kind it has. Adding a fourth question type means
writing one class; nothing that consumes questions has to change.

**Ownership distinguishes the two relationships in the model.** Students and
professors are owned outright by their global registries, so those are
`unique_ptr`. An exam is different: it is referenced by the professor who wrote
it *and* by every student sitting it, with no single owner. Exams are therefore
`shared_ptr`, and the sharing is expressed in the type rather than left as a
comment. Questions, which belong to exactly one exam, go back to `unique_ptr`.

**Console input is funnelled through one function.** `bekhan_adad` in `io.h`
reads a number, and on anything else clears the stream, discards the bad line
and asks again. Every numeric prompt uses it. This matters more than it sounds:
`std::cin >> n` on a letter leaves the stream in a fail state that never
consumes the offending input, so every later read fails instantly and a menu
loop spins forever.

## The data model

Two pairs of parallel vectors connect the three classes, and knowing about them
explains most of the code:

```
azmoon::students  ──►  indices into the global list_stu
azmoon::nomreha   ──►  one grade per entry, parallel to students

student::azmoonha ──►  shared_ptr to each exam the student is on
student::pasokhha ──►  one answer sheet per entry, parallel to azmoonha
```

So a student's grade for an exam is found by locating that student's index in
`azmoon::students` and reading `nomreha` at the same position; their answers are
found by locating the exam in `student::azmoonha` and reading `pasokhha` at the
same position. `jaye_daneshjoo` does the first lookup; the marking screen does
the second by comparing `shared_ptr` identity.

An ungraded student is recorded with the sentinel `NOMRE_DADE_NASHODE`, which
is how the marking screen knows who is still outstanding.

Keeping the pairs aligned is the model's weak point — every enrolment path has
to push to both vectors, and an earlier version of this code did not, which is
why the marking screen read the wrong student's answers. A `vector<struct>`
would make that class of bug impossible, and is the first thing worth changing.

## Source layout

| File | |
|---|---|
| `main.cpp` | registries, menus, and every screen for both roles |
| `soal.h` / `soal.cpp` | the question hierarchy and the `azmoon` exam class |
| `student.h` / `student.cpp` | `student`, with its exams and answer sheets |
| `professor.h` / `professor.cpp` | `professor`, with the exams they wrote |
| `io.h` / `io.cpp` | `bekhan_adad`, the resilient numeric read |

`student` and `professor` each keep a static instance counter, exposed through
`get_num_stu` / `get_num_pro` — a course requirement of the original brief,
kept as written.

## Limitations

Real and worth knowing before reading the code:

**Nothing persists.** All state is in memory. Accounts, exams, answers and
grades are gone when the program exits.

**There is no answer key, so marking is entirely manual.** `soal_gozine` stores
four options but no correct one, and `soal_truefalse` stores no correct value
either. The program cannot mark even a multiple-choice question by itself; the
professor reads the sheet and types a number. Auto-marking would need a correct
answer on each question type.

**The clock is checked between questions, not during one.** A student already
looking at a question has as long as they like to answer it; the limit stops
them being shown the next one. Interrupting a blocking read would need threads
or platform-specific console input.

**Auto-created accounts have a guessable password.** When a professor enrols a
student who has not registered, the account gets the student number as *both*
username and password. Passwords are stored and compared in plain text
throughout.

**Menu choices are not range-checked.** Input that is not a number is rejected
and re-prompted, but a number outside the range on offer — exam 7 of 3 — still
indexes past the end of a vector.

**An exam belongs to one professor**, and there is no way to delete an exam, a
question, a student, or an enrolment.

## Glossary

Menus and prompts are Persian written in Latin characters, the usual workaround
for a Windows console that will not render Persian script. Identifiers follow
the same convention.

| Term | Meaning |
|---|---|
| `azmoon` | exam |
| `soal` | question |
| `gozine` | option, in the multiple-choice sense |
| `tashrihi` | written / free response |
| `nomre` | grade |
| `pasokh` | answer |
| `daneshjoo` | student |
| `asatid` | professors |
| `vorood` | login |
| `sabt nam` | registration |
| `tashih` | marking |
| `tarikhche` | history |
| `moroor` | review |
| `bekhan_adad` | "read a number" |

## Provenance

Written in June 2021 for a second-semester OOP course. The version originally
published to this repository was an earlier Windows Forms attempt — screens that
navigated correctly with no exam logic behind them — and the console code that
actually implemented the assignment was never uploaded. That is corrected here:
the first commit is the 2021 source exactly as written, dated to when it was
written.

The second commit repairs it. The 2021 code did not compile — a stray empty
subscript — and once fixed, marking read from the wrong places. Later work
added the student's side of the exam, which had been left as empty menu
entries.

## Author

Saeed Sabzeh
