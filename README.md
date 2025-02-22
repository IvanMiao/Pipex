![Image](https://github.com/user-attachments/assets/121d80f7-1513-4616-a45d-9cd3abe6ae7a)

## Installation
To compile the program, simply run :
`make`

## Usage
The program `pipex` can be used in two main ways:

1. **Standard Redireciton**: `./pipex infile cmd1 cmd2 ... cmdn outfile`

  This is equivalent to: `< infile cmd1 | cmd2 | ... | cmdn > outfile`

2. **Heredoc Usage**: `./pipex here_doc LIMITER cmd1 cmd2 ... cmdn outfile`

  This is equivalent to: `cmd1 << LIMITER | cmd1 | cmd2 | ... | cmdn > outfile`

## Testing
You can run the provided tests using: 

`make test`

or for valgrind tests:

`make test_val`
