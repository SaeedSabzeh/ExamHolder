#pragma once

// Reads a whole number from stdin. Returns false when input has ended, so the
// caller can shut down instead of spinning. On anything that is not a number it
// clears the error, discards the rest of the line and asks again; without that
// the failed stream would never consume the offending input, every later read
// would fail instantly, and the menu loop would spin forever. Sets n to 0 when
// it returns false, so callers that ignore the result never read a stale value.
bool bekhan_adad(int& n);
