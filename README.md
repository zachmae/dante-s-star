# dante's-star
An epitech 1st year project about generating/solving mazes

this project is an introduction of a complex algorithm to generate random mazes of given sizes

download : git clone https://github.com/zachmae/my_navy.git

how to compile?

simply by using "make" command, i also put make clean, fclean and re command to recompile and clean your folder

you can compile at the root to compile both the generator and the solver or in the respective folders to compile only the part you are interested in

how to use

  generator: (binary in the generator folder)
    ./generator height width (perfect)
      you can precise "perfect" if you want to generate a pefect maze (only one solution from the start to the end)
      algorithm: DFS

  solver: (binary in the solver folder)
    ./solver file
      filepath to the file containing the maze you want to solve
      algorithm: A-STAR
      
or check usage with "./binary -h" for both of them

this project has been made with https://github.com/bania78
