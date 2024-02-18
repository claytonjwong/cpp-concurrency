load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "threadsafe_stack",
    hdrs = ["threadsafe_stack.h"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":threadsafe_stack",
    ],
)
