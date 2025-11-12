Fractol

fract-ol is a 42 school project that renders the Mandelbrot and Julia fractal sets in C using the MiniLibX graphics library.

![Screenshot of Mandelbrot and Julia fractals]
(You can add a screenshot of your program in action here)

Features

Mandelbrot Set: Renders the classic Mandelbrot set.

Julia Set: Renders the Julia set with customizable real and imaginary parameters.

Dynamic Zoom: Zoom in and out of the fractal using the mouse scroll wheel.

Cursor-Focused Zoom: The zoom functionality is centered on the current position of the mouse cursor, allowing for easy exploration.

Dynamic Iterations: The number of iterations increases as you zoom in to reveal more detail.

Smooth Coloring: A simple black-to-white gradient is used to visualize the escape time of each point.

Prerequisites (Linux)

This project is built for Linux and relies on the X11 libraries and libbsd. You can install the necessary dependencies on a Debian-based system (like Ubuntu) using:

sudo apt-get install gcc make xorg libxext-dev libbsd-dev


(This requirement is noted in the minilibx-linux/README.md file)

Building the Project

The provided Makefile will build the libft library, the minilibx-linux library, and the main fractol executable.

Clone the repository:

git clone [https://github.com/your_username/your_repo_name.git](https://github.com/your_username/your_repo_name.git)
cd your_repo_name


Run make:

make


This will create the executable in the bin/ directory.

Usage

The program accepts specific command-line arguments to select the fractal.

Mandelbrot

./bin/fractol mandelbrot


Julia

For the Julia set, you must provide two floating-point numbers representing the real (Re) and imaginary (Im) parts of the complex constant.

./bin/fractol julia <Re> <Im>


Julia Set Examples:

# A classic, swirling shape
./bin/fractol julia -0.7 0.27015

# "The Rabbit"
./bin/fractol julia -0.123 0.745

# Dendrite shape
./bin/fractol julia 0.0 0.8


If you provide incorrect arguments, the program will print a usage message to the standard error output.

Controls

Mouse Scroll Up (Wheel Up): Zoom in.

Mouse Scroll Down (Wheel Down): Zoom out.

Close Window Button (Red 'X'): Shuts down the program and performs a clean exit.
