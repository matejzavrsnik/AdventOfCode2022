# Learned

What I learned doing Advent of Code and how to be better next time.

- C++ is verbose, and it's slowing me down. Liberally use `using namespace std;` and prepare aliases for commonly used stuff
- Have a header when everything is already included so that I don't need to write `#include` every 10 seconds at the start of a puzzle
- Watch out which coordinate system I'm working with. There are three. Going north-east means different index manipulations in every one.
- Build yourself a library of utilities because problems keep needing similar tools.
- Completely abstract vector of vectors away. It messes up the coordinate systems, because it swaps x and y in my mind. Write `grid` class and never expose underlying vector of vectors, then make all the logic go through that. I've debugged vector of vectors enough.
- Don't use int. Overflows are hard to notice. Use `long long`. And because that's a lot to type, have `using ll = long long` ready in your header file.
- Normally you'd write code that's reusable in other contexts. Shake off that urge now. Write for a concrete case at hand. Especially in C++ it's easy to go down the rabbit hole and try to do everything perfectly reusable with type safety, const correctness, templates, concepts, etc.
- When solving a puzzle, do what you need to do, but when done go through the code and extract possibly reusable stuff into own methods and generalise. They will come handy in next puzzles.
- Don't overcomplicate. Sometimes cigar is just a cigar.
- Making copies of stuff and passing them around as copies was not a performance bottleneck. Make liberal use of copying data because that makes code simpler and less buggy. If you feel you need to optimise argument into `const&` to make it faster, you're on a wrong path.
- Resist the urge to align code nicely and similar wastes of time. This isn't about beauty.
- Prepare entire project structure in advance: the data file, the two functions for `part1` and `part2`, etc. That's easily 5 minutes in the morning.
- If you have the function that will calculate the submission split into two, one can read file and other can work on data. That is useful when you want to make it work on custom data because you don't need to make it read a file to do it, or extract functionality on the spot and waste additional time.
- Don't debug, print_container_template. Have print_container_template functions prepared for all possible data structures, because visualised values are the quickest way to debug.
- There is no one way to do Advent of Code. You can do it for speed and engage with leaderboards, to learn some language better, to pass time, to get ideas for expanding your utilities library, to practice coding, etc. And once you decide what you want out of AoC, you don't need to stick to it. It's not work. And there's nothing to prove because nobody cares how well you did or did not do :)
- The goal is to solve the specific challenge, not in general. For example, hard-coding challenge specifics is a common shortcut.
- When extracting reusable code, make a copy, move that, and leave original where it was. You don't want to be refactoring all past AoC code whenever you want to improve reusable code.
- Before AoC starts, go through standard library, my library, AoC library to remind yourself what's there.
- Use existing building blocks and combine, rather than build custom code.