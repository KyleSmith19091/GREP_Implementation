# GREP Implementation

This is a naive implementation of the GNU grep tool, it follows the same algorithm for the string matching which is the **Boyer Moore**
string matching algorithm. This is implmented using c++11.

## How to Use?

### Installation
#### 1. First clone the repo
```shell
$ git clone https://github.com/sKorpion19091/GREP_Implementation.git
```

#### 2. Build it from source.

This project needs to be built from source. So make sure you have the *make* command available.

```shell
$ make
```

This will then build a binary inside the build directory. 

#### 3. Usage
So we can run the program as follows: 

```shell
$ ./build/main pattern "this is a pattern matching string"
```

The output will look something like this:
```shell
$ this is a "pattern" matching string
```
**Note this will only work if ANSI colors are supported on your terminal.
