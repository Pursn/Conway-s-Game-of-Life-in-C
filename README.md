# It's Conway's Game of Life in C
I needed to do something, so I have decided to make Conway's Game of Life in my Linux terminal. I wanted to make it in C so I can be prepared for my sophomore year of university.

## The Rules of Conway's Game of Life
The rules can be found at the [Conway's Game of Life Wiki](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#:~:text=Rulesedit).

### Rule 1: *Underpopulation*
Any alive cells will die if there are fewer than two neighbouring alive cells.
### Rule 2: *Survival*
Any alive cells will live if there are two or three neighbouring alive cells.
### Rule 3: *Overpopulation*
Any alive cells will die if there are more than three neighbouring alive cells.
### Rule 4: *Reproduction*
Any dead cells will turn into an alive cell if there are **exactly** three neighbouring alive cells.
