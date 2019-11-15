# Sprite Coder

## Build

### Build on maintainer’s system:
```
aclocal # Set up an m4 environment
autoconf # Generate configure from configure.ac
automake --add-missing # Generate Makefile.in from Makefile.am
./configure # Generate Makefile from Makefile.in
make distcheck # Use Makefile to build and test a tarball to distribute
```

### Build on the end-user’s system:
```
./configure # Generate Makefile from Makefile.in
make # Use Makefile to build the program
make install # Use Makefile to install the program
```

### [The magic behind configure, make, make install](https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install)


## License

For detailed explanation on how things work, checkout the [wiki](https://github.com/GreenDjango/sprite-coder/wiki)
- [CHANGELOG](./CHANGELOG.md)
- ![version-badge](https://img.shields.io/badge/version-0.1.0-blue.svg)
- ![license-badge](https://img.shields.io/badge/license-MIT-brightgreen.svg)
