# ExamHolder (آزمون‌یار)

A console exam management system for professors and students, written in C++ as
second-semester object-oriented programming coursework, spring 2021.

Professors create exams, write questions of three different types, enrol
students and grade them. Students register, log in and see the exams they are
enrolled in.

## Building

Open `ExamHolder.sln` in Visual Studio 2019 or later and build. The project
targets the v142 toolset; Visual Studio 2022 will offer to retarget it to v143,
which is fine.

There are no third-party dependencies, but the program is Windows-only: it
clears the screen with `system("cls")`. It compiles elsewhere and will simply
print the command name instead of clearing.

## Design

**Questions use runtime polymorphism.** An abstract `soal` base class holds the
question text and declares a pure virtual `show()`. Three subclasses implement
it: `soal_gozine` (multiple choice, four options), `soal_truefalse`, and
`soal_tashrihi` (free response). An exam stores its questions as
`vector<unique_ptr<soal>>`, so a fourth question type means adding one class and
touching nothing else.

**Exams are the `azmoon` class** — a name, a duration in minutes, the question
list, the enrolled students, and their grades.

**Ownership reflects the two kinds of relationship in the model.** Students and
professors are owned outright by the global registries, so those hold
`unique_ptr`. An exam is referenced by the professor who created it *and* by
every student sitting it, so exams are `shared_ptr`. The sharing lives in the
type rather than in a comment.

## Features

Registration and login for both roles, with password verification and rejection
of usernames already taken by either a student or a professor.

A professor can:

- create an exam and set its duration
- add questions of any of the three types
- enrol students by name and student number, creating an account for anyone not
  already registered
- rename an exam or change its duration afterwards
- review past exams with each student's grade
- enter grades for students who do not yet have one

A student can log in and list the exams they are enrolled in.

## Limitations

This is a one-term course project, and it stops where the term did.

**Sitting an exam is not implemented.** The student panel lists enrolled exams,
but the "take exam" and "view grades" entries are stubs. The answer field the
grading screen reads from is therefore never filled: a professor can enter
grades, but there are no submitted answers to grade against.

**Nothing persists.** All state is in memory and is lost when the program exits.

**The exam duration is not enforced.** A professor sets it and it is displayed,
but no timer acts on it.

**Menu choices are not range-checked.** Input that is not a number is rejected
and re-prompted, but a number outside the range on offer — exam 7 of 3 — still
indexes past the end of a vector.

## Interface language

Menus and prompts are Persian written in Latin characters, the usual workaround
for a Windows console that will not render Persian script. Identifiers follow
the same convention:

| Term | Meaning |
|---|---|
| `azmoon` | exam |
| `soal` | question |
| `gozine` | option (multiple choice) |
| `tashrihi` | free response |
| `nomre` | grade |
| `pasokh` | answer |
| `daneshjoo` | student |
| `asatid` | professors |
| `vorood` | login |
| `sabt nam` | registration |
| `tashih` | grading |
| `tarikhche` | history |

## Author

Saeed Sabzeh
