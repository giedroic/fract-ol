# fract'ol

**fract‑ol** is a graphical program written in C that allows users to explore and visualize mathematical fractals such as the Mandelbrot and Julia sets.  
It uses the **MiniLibX** library for rendering and supports real‑time zooming and interaction.

---

## Overview

Fractals are mathematical sets that exhibit a repeating pattern at every scale.  
This project provides an intuitive interface for visualizing these complex shapes, highlighting the beauty of mathematics through graphical computation.

---

## Features

- Interactive rendering of **Mandelbrot** and **Julia** fractals  
- Real‑time **zooming** using the mouse scroll wheel  
- Smooth **color gradients** based on iteration counts  
- **Configurable Julia constants** via command‑line arguments  
- Lightweight C implementation using **MiniLibX** and **libft**  

---

## Requirements

This program is intended for **Linux** systems. The following packages are required:

```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

---

## Installation

Clone the repository and build the project using the provided `Makefile`:

```bash
git clone https://github.com/giedroic/fract-ol.git
cd fract-ol
make
```

After compilation, the executable `fractol` will be available in the `bin/` directory.

---

## Usage

Run the program with one of the available fractal options:

### Mandelbrot Set
```bash
./bin/fractol mandelbrot
```

### Julia Set
Provide the real and imaginary parts of the complex constant as arguments:

```bash
./bin/fractol julia <Re> <Im>
```

#### Example
```bash
./bin/fractol julia -0.7 0.27015
```

If the arguments are incorrect or incomplete, the program will display a usage message.

---

## Controls

| Action | Description |
|--------|--------------|
| Mouse Scroll Up | Zoom in |
| Mouse Scroll Down | Zoom out |
| Close Window | Exit program |

---

## Notes

- Performance depends on system capabilities and the zoom depth.  
- Julia constants significantly affect the resulting shape — experiment with different values!  

---
