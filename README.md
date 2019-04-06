# :dollar: cnote :dollar:
`cnote` is a simple command line utility for taking quick notes.

## Installation
Simply run

```bash
make
```

Or, since the program is simple enough, simply run:

```bash
gcc cnote.c -o cnote
```

And then move the resulting executable to anywhere on your enivornment path. I put mine in ~/bin.

## Usage
`cnote` stores your notes in `$HOME/.cnotes`. Notes are opened in whatever `$EDITOR` is in your environment. If there is no `$EDITOR` environment variable, `vim` is default. I recommend vim anyway because what else would you use?!

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
* Move functions into header files, maybe.
* Add an "archiving" system so notes aren't really deleted.
