# Build + Run
```
bazel build :main && bazel-bin/main
```

# Cleanup
```
bazel clean --expunge
```

# Question

Why so many different outputs?  What's going on here?

```
➜  03_sharing_data git:(main) ✗ bazel build :main && bazel-bin/main
INFO: Analyzed target //:main (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //:main up-to-date:
  bazel-bin/main
INFO: Elapsed time: 0.830s, Critical Path: 0.75s
INFO: 3 processes: 1 internal, 2 darwin-sandbox.
INFO: Build completed successfully, 3 total actions
********** Sequentially **********
🍎 copy: _________9
🍎 copy: ________8
🍎 copy: _______7
🍎 copy: ______6
🍎 copy: _____5
🍎 copy: ____4
🍎 copy: ___3
🍎 copy: __2
🍎 copy: _1
🍎 copy: 0
🍊 deep: _________9
🍊 deep: ________8
🍊 deep: _______7
🍊 deep: ______6
🍊 deep: _____5
🍊 deep: ____4
🍊 deep: ___3
🍊 deep: __2
🍊 deep: _1
🍊 deep: 0
********** Concurrently **********
🍏 orig: _________9
🍏 orig: ________8
🍏 orig: _______7
🍏 orig: ______6
🍏 orig: _____5
🍏 orig: ____4
🍏 orig: ___3
🍏 orig: __2
🍏 orig: _1
🍏 orig: 0
➜  03_sharing_data git:(main) ✗ bazel build :main && bazel-bin/main
INFO: Analyzed target //:main (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //:main up-to-date:
  bazel-bin/main
INFO: Elapsed time: 0.074s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
********** Sequentially **********
🍎 copy: _________9
🍎 copy: ________8
🍎 copy: _______7
🍎 copy: ______6
🍎 copy: _____5
🍎 copy: ____4
🍎 copy: ___3
🍎 copy: __2
🍎 copy: _1
🍎 copy: 0
🍊 deep: _________9
🍊 deep: ________8
🍊 deep: _______7
🍊 deep: ______6
🍊 deep: _____5
🍊 deep: ____4
🍊 deep: ___3
🍊 deep: __2
🍊 deep: _1
🍊 deep: 0
********** Concurrently **********
🍎 copy: _________9
🍎 copy: ________8
🍎 copy: _______7
🍎 copy: ______6
🍎 copy: _____5
🍎 copy: ____4
🍎 copy: ___3
🍎 copy: __2
🍎 copy: _1
🍎 copy: 0
🍊 deep: __2
🍊 deep: _1
🍊 deep: 0
🍏 orig: _________9
🍏 orig: ________8
🍏 orig: _______7
🍏 orig: ______6
🍏 orig: _____5
🍏 orig: ____4
🍏 orig: ___3
🍏 orig: __2
🍏 orig: _1
🍏 orig: 0
➜  03_sharing_data git:(main) ✗ bazel build :main && bazel-bin/main
INFO: Analyzed target //:main (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //:main up-to-date:
  bazel-bin/main
INFO: Elapsed time: 0.075s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
********** Sequentially **********
🍎 copy: _________9
🍎 copy: ________8
🍎 copy: _______7
🍎 copy: ______6
🍎 copy: _____5
🍎 copy: ____4
🍎 copy: ___3
🍎 copy: __2
🍎 copy: _1
🍎 copy: 0
🍊 deep: _________9
🍊 deep: ________8
🍊 deep: _______7
🍊 deep: ______6
🍊 deep: _____5
🍊 deep: ____4
🍊 deep: ___3
🍊 deep: __2
🍊 deep: _1
🍊 deep: 0
********** Concurrently **********
🍎 copy: _________9
🍎 copy: ________8
🍎 copy: _______7
🍎 copy: ______6
🍎 copy: _____5
🍎 copy: ____4
🍎 copy: ___3
🍎 copy: __2
🍎 copy: _1
🍎 copy: 0
🍏 orig: _________9
🍏 orig: ________8
🍏 orig: _______7
🍏 orig: ______6
🍏 orig: _____5
🍏 orig: ____4
🍏 orig: ___3
🍏 orig: __2
🍏 orig: _1
🍏 orig: 0
🍊 deep: _______7
🍊 deep: ______6
🍊 deep: _____5
🍊 deep: ____4
🍊 deep: ___3
🍊 deep: __2
🍊 deep: _1
🍊 deep: 0
➜  03_sharing_data git:(main) ✗
```