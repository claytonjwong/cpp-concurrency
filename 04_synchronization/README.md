# Build + Run
```
bazel build :main && bazel-bin/main
```

# Cleanup
```
bazel clean --expunge
```

# TODO

This output looks legit, let's play around with this tomorrow, then implement a thread safe priority queue 🤘

```
➜  04_synchronization git:(main) ✗ bazel build :main
INFO: Analyzed target //:main (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //:main up-to-date:
  bazel-bin/main
INFO: Elapsed time: 0.766s, Critical Path: 0.68s
INFO: 3 processes: 1 internal, 2 darwin-sandbox.
INFO: Build completed successfully, 3 total actions
➜  04_synchronization git:(main) ✗ ./bazel-bin/main
0x16af6b000 produce 🔨0x16aff7000 produce 🔨
0x16b19b000 produce 🔨
0x16b227000 produce 🔨
0x16b10f0000x16b33f000 produce 🔨0x16b2b3000 produce 🔨

0x16b457000 produce 🔨
0x16b3cb000 produce 🔨
0x16b083000 produce 🔨

 produce 🔨
0x16af6b0000x16b457000 done 🍺0x16b3cb000
 done 🍺
0x16b2b30000x16b083000 done 🍺
0x16b33f0000x16b457000 produce 🔨0x16b0830000x16aff70000x16b3cb000 produce 🔨
 done 🍺

0x16b10f000 done 🍺0x16b227000 done 🍺 done 🍺
 done 🍺

0x16b19b000 done 🍺0x16b227000
0x16b2b3000 produce 🔨 produce 🔨
0x16b19b0000x16af6b000
 produce 🔨

 produce 🔨0x16b10f000 produce 🔨
0x16aff7000 produce 🔨
 produce 🔨

 done 🍺
0x16b33f000 produce 🔨
0x16b2b3000 done 🍺0x16b3cb000
0x16b2b3000 produce 🔨
 done 🍺
0x16b3cb000 produce 🔨
0x16af6b000 done 🍺
0x16af6b000 produce 🔨
0x16aff7000 done 🍺
0x16aff7000 produce 🔨
0x16b0830000x16b33f000 done 🍺 done 🍺
0x16b083000 produce 🔨

0x16b33f000 produce 🔨
0x16b457000 done 🍺
0x16b457000 produce 🔨
0x16b10f000 done 🍺
0x16b10f000 produce 🔨
0x16b227000 done 🍺
0x16b19b000 done 🍺
0x16b19b000 produce 🔨
0x16b227000 produce 🔨
0x16b2b3000 done 🍺
0x16b2b3000 produce 🔨
0x16b3cb000 done 🍺
0x16b3cb000 produce 🔨
0x16af6b000 done 🍺
0x16b0830000x16b227000 done 🍺 done 🍺
0x16b227000 produce 🔨
0x16aff7000 done 🍺
0x16aff7000 produce 🔨
0x16af6b000
0x16b083000 produce 🔨
 produce 🔨
0x16b33f000 done 🍺
0x16b33f000 produce 🔨
0x16b10f000 done 🍺
0x16b10f000 produce 🔨
0x16b457000 done 🍺
0x16b457000 produce 🔨
0x16b19b000 done 🍺
0x16b19b000 produce 🔨
0x16b2b3000 done 🍺
0x16b2b3000 produce 🔨
0x16b3cb000 done 🍺
0x16b3cb000 produce 🔨
0x16b457000 done 🍺
0x16b457000 produce 🔨
0x16aff7000 done 🍺
0x16aff7000 produce 🔨
0x16b33f000 done 🍺
0x16b33f000 produce 🔨
0x16b227000 done 🍺
0x16b227000 produce 🔨
0x16b10f000 done 🍺
0x16b10f000 produce 🔨
0x16b083000 done 🍺
0x16b083000 produce 🔨
0x16af6b000 done 🍺
0x16af6b000 produce 🔨
0x16b19b000 done 🍺
0x16b19b000 produce 🔨
0x16b2b3000 done 🍺
0x16b2b3000 produce 🔨
0x16b3cb0000x16b457000 done 🍺
0x16b10f000 done 🍺
0x16b10f000 produce 🔨
0x16b0830000x16aff70000x16af6b000 done 🍺 done 🍺
0x16b3cb000 produce 🔨
 done 🍺0x16b457000 produce 🔨
0x16b227000 done 🍺

0x16b083000 produce 🔨
 done 🍺
0x16aff7000 produce 🔨
0x16b227000 produce 🔨
0x16b33f000 done 🍺
0x16af6b000 produce 🔨

0x16b33f000 produce 🔨
0x16b19b000 done 🍺
0x16b19b000 produce 🔨
0x16b2b3000 done 🍺
0x16b2b3000 produce 🔨
0x16b10f000 done 🍺
0x16b10f000 produce 🔨
0x16aff7000 done 🍺0x16b457000 done 🍺

0x16b457000 produce 🔨
0x16b19b0000x16af6b0000x16b33f000 done 🍺0x16b227000
0x16aff7000 produce 🔨0x16b083000 done 🍺

0x16b3cb000 done 🍺 done 🍺 done 🍺

0x16b33f000 produce 🔨
0x16b2270000x16b083000 produce 🔨 produce 🔨

0x16af6b000 produce 🔨

0x16b3cb000 produce 🔨
 done 🍺
0x16b19b000 produce 🔨
0x16b2b3000 done 🍺
0x16b2b3000 produce 🔨
0x16b10f000 done 🍺
0x16b10f000 produce 🔨
0x16b457000 done 🍺
0x16b457000 produce 🔨
0x16aff7000 done 🍺
0x16aff7000 produce 🔨
0x16b33f000 done 🍺
0x16b33f000 produce 🔨
0x16b3cb000 done 🍺
0x16b3cb000 produce 🔨
0x16b227000 done 🍺
0x16b227000 produce 🔨
0x16b083000 done 🍺
0x16b083000 produce 🔨
0x16af6b000 done 🍺
0x16af6b000 produce 🔨
0x16b19b000 done 🍺
0x16b19b000 produce 🔨
0x16b2b3000 done 🍺
0x16b2b3000 produce 🔨
0x16b457000 done 🍺
0x16b457000 produce 🔨
0x16b3cb000 done 🍺
0x16b3cb000 produce 🔨
0x16aff7000 done 🍺
0x16aff7000 produce 🔨
0x16b33f000 done 🍺
0x16b33f000 produce 🔨
0x16b227000 done 🍺
0x16b227000 produce 🔨
0x16b083000 done 🍺
0x16b083000 produce 🔨
0x16b19b000 done 🍺
0x16af6b000 done 🍺0x16b19b000 produce 🔨0x16b10f000
 done 🍺
0x16b10f000 produce 🔨

0x16af6b000 produce 🔨
0x16b2b3000 done 🍺
0x16b2b3000 produce 🔨
0x16b457000 done 🍺
0x16b457000 produce 🔨
0x16aff7000 done 🍺
0x16aff7000 produce 🔨
0x16b3cb000 done 🍺
0x16b3cb000 produce 🔨
0x16b33f000 done 🍺
0x16b33f000 produce 🔨
0x16b083000 done 🍺
0x16b083000 produce 🔨
0x16b227000 done 🍺
0x16b227000 produce 🔨
0x16af6b000 done 🍺
0x16af6b000 produce 🔨
0x16b19b000 done 🍺
0x16b19b000 produce 🔨
0x16b10f000 done 🍺
0x16b10f000 produce 🔨
0x16aff7000 done 🍺
0x16b3cb000 done 🍺
0x16b33f000 done 🍺
0x16b083000 done 🍺
0x16b2b3000 done 🍺
0x16b457000 done 🍺
0x16b227000 done 🍺
0x16b19b000 done 🍺
0x16b10f000 done 🍺
0x16af6b000 done 🍺
➜  04_synchronization git:(main) ✗
```
