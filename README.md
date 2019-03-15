# :dollar: cnote :dollar:
`cnote` is a simple command line utility for taking quick notes.

## Installation
I will write a makefile once I learn how to do so. In the meantime, the program is simple enough:

```bash
gcc cnote.c -o cnote
```

And then move the resulting executable to anywhere on your enivornment path. I put mine in ~/bin.

## Usage
`cnote` stores your notes in `$HOME/.cnotes`. Notes are opened in whatever `$EDITOR` is in your environment. I recommend vim because what else would you use?!

To list the available note files, simply type

```bash
cnote
```

or

```bash
cnote -l
```

To create a note or edit an existing one, enter that as the first and only argument:

```bash
cnote filename
```

You can delete an existing file with:

```bash
cnote -d filename
```

Note files are markdown files, but you should never actually type .md when using cnote.

## TODO
* Implement make.
* Move functions into header files, maybe.
* Add an "archiving" system so notes aren't really deleted.
