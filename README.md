# 📚 Libft

A custom C library implementing standard libc functions and additional utilities.

## 🎯 Overview

Libft is a foundational project focused on recreating essential C standard library functions. This project provides hands-on experience with:

- String manipulation
- Memory management
- Linked list operations

> **Note:** This library is a living project—written in pencil, not pen. It will continue to evolve with new functions and improvements as it accompanies future projects.

## 🚀 Getting Started

### Compilation

Build the base library:

```bash
make
```

This creates `libft.a`, ready to be linked with your programs.

### Bonus Functions

To include linked list functions:

```bash
make bonus
```

## 🧪 Testing

The project includes comprehensive tests located in `./.tests/`, built using the **atf-c** framework with **Kyua** test runner.

### Dependencies

Before running tests, ensure you have the required testing tools installed:

**Linux (Debian/Ubuntu):**
```bash
sudo apt-get update
sudo apt-get install kyua libatf-dev atf-sh
```

**Linux (Fedora/RHEL):**
```bash
sudo dnf install kyua atf
```

**Linux (Arch):**
```bash
sudo pacman -S kyua atf
```

**FreeBSD:**
```bash
pkg install kyua atf
```

**NetBSD (with pkgsrc):**
```bash
pkgin install kyua atf
```

**OpenBSD:**
```bash
pkg_add kyua atf
```

**macOS:**
```bash
brew install kyua atf
```

**Windows (WSL):**

Use Windows Subsystem for Linux and follow the Linux instructions above, or:

```bash
# Using WSL with Ubuntu
wsl --install
# Then inside WSL:
sudo apt-get update
sudo apt-get install kyua atf-sh
```

> **Note:** Native Windows support is limited. WSL is the recommended approach for Windows users.

### Compiling Tests

**Compile all tests:**
```bash
make
```

**Compile specific test(s):**
```bash
make TEST="function_test"
```

**Compile multiple tests:**
```bash
make TEST="function1_test function2_test function3_test"
```

> **Note:** Test names should be specified without the `.c` extension.

### Running Tests

**Run all tests:**
```bash
kyua test
```

**Run specific test:**
```bash
kyua test function_test
```

**Debug specific test case:**
```bash
kyua debug function_test:test_case
```

**List available test cases:**
```bash
kyua list function_test
```

## 📖 Documentation

Each function is tested individually, ensuring reliability and correctness. Browse the `.tests/` directory to explore test cases and understand function behavior.

## 🛠️ Usage

Link the compiled library with your project:

```bash
gcc your_program.c -L. -lft -o your_program
```

---

*Building the foundation, one function at a time.*
