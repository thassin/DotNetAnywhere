# DotNetAnywhere

DotNetAnywhere (DNA) is a small interpreted .NET CIL runtime. The original [code](https://github.com/chrisdunelm/DotNetAnywhere) by Chris Bacon has been adjusted by Steve Sanderson in his first versions of [Blazor](https://blazor.net), and this version related to WebAssembly is available [here](https://github.com/boyanio/DotNetAnywhere).

This version adds porting to 64-bit platforms, and some debugging options. The 64-bit port is not yet complete, or thoroughly tested, for some examples which work see the `testcases\_passing\_64bit` folder. Expect more testcases to appear there in the future.

## Build

From the `native` folder you can find:
- `README_versions.txt` : a document briefly explaining the approach to 64-bit port.
- `src_original` : the original source related to WebAssembly and Blazor development.
- `src32` : a modified 32-bit version with debugging options added.
- `src64` : the 64-bit port with debugging options added.

There is a default Makefile in the `native/src64` folder, so you can try the following:

```
cd native/src64
make
```

The executable `dna64` is generated in the `native/src64` folder.

