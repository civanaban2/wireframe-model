# Wireframe Model

An interactive height-map renderer written in C with MiniLibX and X11.
The program reads a grid of elevation values from an `.fdf` file, transforms
the points, and connects neighboring vertices to display a wireframe terrain.
Developed as a 42 graphics project.

## Features

- Grid-based height-map parsing.
- Three-axis rotation through a rotation matrix.
- Keyboard-controlled translation, zoom, and elevation scaling.
- Six color modes, including elevation-based palettes.
- Incremental line rasterization and color interpolation.
- Rendering into an image buffer before displaying the frame.

## Requirements

The current Makefile targets **Linux/X11** and links `mlx_Linux`, `Xext`, `X11`,
and the math library. Use a C compiler, Make, Git, X11 development files, and a
working graphical X11 session.

For Debian/Ubuntu, the MiniLibX dependency documents these prerequisites:

```sh
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

See the [MiniLibX Linux requirements](https://github.com/42paris/minilibx-linux#readme)
for details. The repository does not provide a native macOS/Cocoa build target;
a Linux environment with an available X display is the intended setup for the
existing Makefile. A headless terminal alone cannot display the viewer.

## Build

Both dependencies are Git submodules:

- `lib/libft`: string, allocation, parsing, and output helpers.
- `lib/minilibx`: the MiniLibX X11 graphics library.

```sh
git clone --recurse-submodules https://github.com/civanaban2/wireframe-model.git
cd wireframe-model
make
```

For an existing clone:

```sh
git submodule update --init --recursive
make
```

The executable is `build/fdf`. The Makefile builds the pinned dependency
revisions; it does not automatically initialize missing submodules.

## Run

```sh
./build/fdf maps/42.fdf
./build/fdf maps/pyramide.fdf
```

The program opens a 1920 x 1080 window titled `FDF`. Give it keyboard focus to
use the controls. Start with a small bundled map before trying a large terrain.
Close the window or press Escape to exit.

## Controls

| Keys | Action |
| --- | --- |
| `W` / `S` | Rotate around one horizontal camera axis |
| `A` / `D` | Rotate around the other horizontal camera axis |
| `Q` / `E` | Rotate in the screen plane |
| Arrow keys | Move the map horizontally or vertically |
| `Z` / `X` | Zoom in / out |
| `U` / `J` | Increase / decrease elevation scale by 0.05 |
| `Y` / `H` | Increase / decrease elevation scale by 0.5 |
| `I` | Set the angled view preset |
| `K` | Set rotations to zero for a top view |
| `R` | Reset camera rotation, translation, zoom, and elevation scale |
| `1` | White wireframe |
| `2` | Topographic palette |
| `3` | Terrain palette |
| `4` | Cartoon palette |
| `5` | Realistic-style palette |
| `6` | Custom palette |
| Escape | Close the application |

Both uppercase and lowercase letter keys are handled. The camera reset does
not reset the selected color palette.

## Map format

Use a nonempty rectangular grid of integer elevations, separated by spaces.
Each row must end with a newline, including the final row, because the current
parser determines height by counting newline characters.

```text
0 0 0 0
0 2 2 0
0 2 4 0
0 0 0 0
```

Save the example as `example.fdf` and launch `./build/fdf example.fdf`.
Rows and columns determine horizontal point positions; integer values determine
height. The default elevation scale exaggerates vertical differences.

The filename must have a nonempty basename and a lowercase `.fdf` extension.
Input color suffixes are not separately parsed; display colors come from the
selected palette. The map collection includes malformed fixtures as well as
valid examples, so not every file in `maps/` is an intended successful input.

## Rendering flow

1. Read map dimensions and allocate a grid of points.
2. Assign grid coordinates and elevation values.
3. Select elevation-based colors and apply zoom and elevation scaling.
4. Rotate the points, then translate their screen coordinates.
5. Draw horizontal and vertical neighbor connections into the image buffer.
6. Display the image and redraw after a supported key event.

The renderer projects rotated coordinates onto the screen without a perspective
divide. It is a wireframe viewer, not a filled-polygon or perspective 3D engine.

## Make targets

| Command | Action |
| --- | --- |
| `make` | Build libft, MiniLibX, and the renderer |
| `make clean` | Remove project objects and clean libft objects |
| `make fclean` | Also remove the executable, libft archive, and MiniLibX build output |
| `make re` | Clean and rebuild; run without parallel `-j` |

## Structure

```text
inc/fdf.h
src/
  fdf.c                 # Entry point and graphics initialization
  parser.c              # Map dimensions and point loading
  error.c               # Argument, file and extension checks
  rotation_matrix.c     # Point rotation
  draw_map.c            # Image buffer and pixel output
  line_utils.c          # Neighbor connections and line drawing
  colorize.c            # Color-mode dispatch
  color_modes.c         # Elevation palettes
  hooks_core.c          # Input dispatch, reset and shutdown
  hooks_view.c          # Camera and palette controls
  free_stuff.c          # Allocation cleanup
maps/                   # Sample and extended maps
lib/libft/              # Git submodule
lib/minilibx/           # Git submodule
```

## Scope and limitations

The parser assumes regular rows and valid integer values. File existence and
extension checks are not complete map validation; malformed or very large
inputs can expose allocation and parsing issues. A small map is the safest
starting point for exploring the viewer.

The graphics configuration is fixed, and integer typedefs, image layout,
resource cleanup, and some camera bounds are platform-dependent or require
further review. These are descriptions of the existing implementation;
this README update does not change its behavior.

## License

MIT for this project; see [LICENSE](LICENSE). Dependency repositories retain
their own licenses.
