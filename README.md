# It's Conway's Game of Life in C
I needed to do something, so I have decided to make Conway's Game of Life in my Linux terminal. I wanted to make it in C so I can be prepared for my sophomore year of university.

Skip rules to [Pre-Building](#Pre-Building)

## The Rules of Conway's Game of Life
The rules can be found at the [Conway's Game of Life Wiki](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#:~:text=Rulesedit).

### Rule 1: *Underpopulation*
Any alive cells will die if there are fewer than two neighboring alive cells.
### Rule 2: *Survival*
Any alive cells will live if there are two or three neighboring alive cells.
### Rule 3: *Overpopulation*
Any alive cells will die if there are more than three neighboring alive cells.
### Rule 4: *Reproduction*
Any dead cells will turn into an alive cell if there are **exactly** three neighboring alive cells.

## Pre-Building
I made building this project very easy to build since this is just a project I made to teach myself more about C.

Install the basic development tools needed to code in C. This package group contains packages like gcc, make, git, and others that will be necessary for coding in C/C++.

### Fedora
```
sudo dnf install @development-tools
```

### Debian/Ubuntu
```
sudo apt install build-essential
```
## Building
Download this repo by opening your terminal and writing the following command.
```
git clone https://github.com/Pursn/Conway-s-Game-of-Life-in-C.git
```
This will just copy all the files of this repo to your home directory or wherever your current directory is stated in your terminal prompt.

Go to the repo's directory by using this command:
```
cd Conway-s-Game-of-Life-in-C
```

Building this project is super easy since every command needed will be in the Makefile. 

In the repo's directory, build the project by typing:
```
make project
```
To run it, you can type:
```
make run
```
OR
```
./cgol
```
To remove the executable if you don't want it anymore or you are recompiling, use this:
```
make clean
```

## Educational Experimentation
Look, I know nobody is really going to download this repo to run it.
I doubt that anybody is really going to see this, but I have tried to organize my C code with comments so I can learn from this and maybe somebody else can learn from this.
This repo is designed to experiment around and have fun passing the time, so enjoy.
