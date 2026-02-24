# Reverse CCT - Cognitive Control Task

## Overview

**Reverse CCT** is a cognitive control training application designed to enhance emotional regulation and inhibitory control. The task requires players to continuously add heard digits and provide responses within timed intervals while managing inhibitory control through "No-Go" signals.

**Two Tasks in One**: Reverse CCT fuses the Cognitive Control Task (counting numbers) with the Stop Signal Task (inhibition control) into a unified experience. This is an experimental tool.

- **CCT** is designed to help with emotional regulation by decreasing rumination, depression symptoms, and impulsivity
- **GNG/SST** helps with controlling addiction issues and behavioral change

### Resources

**CCT Tool**
- https://cct1.netlify.app/

**Inhibitory Control Tasks**
- https://www.psytoolkit.org/experiment-library/experiment_go-no-go.html
- https://www.psytoolkit.org/experiment-library/experiment_stopsignal.html

### Scientific Research

**CCT Task**
- https://www.sciencedirect.com/science/article/abs/pii/S016503272101421X?via%3Dihub
- https://www.sciencedirect.com/science/article/abs/pii/S0005796718300457?via%3Dihub
- https://dl.acm.org/doi/10.1145/3675094.3677591

**Inhibitory Control Tasks**
- https://www.sciencedirect.com/science/article/pii/S0195666324000163

### Key Features

- **Number Sequence Generation** : Digits are played via audio synthesis and must be continuously added
- **No-Go Signal** : An audio signal randomly instructs the player not to respond (inhibitory control test)
- **Adaptive Difficulty** : Time intervals between digits increase or decrease based on performance
- **Streak System** : Tracks consecutive correct/incorrect responses before interval modification

## Game Mechanics

### Trial Flow
1. A new digit is generated and played as audio
2. The player has a timed interval (initially 1600 ms) to mentally add the digit to the running sum
3. The player enters their response (0-9), which must be the units digit of the sum
4. **Go Trials** : The player must respond correctly before the interval ends
5. **No-Go Trials** : An audio signal (~25% probability) instructs the player NOT to respond

### Difficulty Adjustment
- **Correct Streak** (4 consecutive correct responses) : Decreases interval (increases difficulty)
- **Error Streak** (4 consecutive errors) : Increases interval (decreases difficulty)
- Difficulty Range : 500 ms (hardest) to 1600 ms (easiest)

## Technical Challenges

### 1. **Memory Management**
- **Challenge** : Properly allocate and deallocate persistent game structures
- **Solution** : Global pointer `reverseCCTGame` with allocation failure checking (`isAllocFailing()`)
- **Complexity** : Tracking the complete lifecycle of the game structure throughout execution

### 2. **Precise Timing Management**
- **Challenge** : Maintain precise time intervals while capturing user input asynchronously
- **Solution** : Use `Sleep()` for delays and the `_kbhit()` function to asynchronously query the message queue for keypresses
- **Complexity** : Synchronization between audio playback, delays, and responsive input capture on Windows

### 3. **Modular C Architecture**
- **Challenge** : Organize complex C code into maintainable and reusable modules
- **Solution** : Hierarchical directory structure separating concerns:
  - `data/` : Structures and constants
  - `game_logic/` : Core task logic
  - `handle_inputs/` : Input management
  - `handle_sound/` : Audio handling
- **Complexity** : Managing interdependencies and explicit memory allocation across modules


## Project Structure

```
reverse_cct/ (root folder)
├── reverse_cct/ (executable folder)
│   ├── reverse_cct.exe              # Executable file
│   ├── sounds/
│   │   └── digits/                  # Audio files (0-9)
│   └── ...
├── main.c                           # Game loop source code
└── src/backend/
    ├── data/
    │   ├── constants.h              # Game parameters (intervals, streaks)
    │   └── structs.h                # Game and NoGoSignal structures
    ├── game_logic/
    │   ├── game_logic.h/c           # Core logic
    │   ├── handle_inputs/
    │   │   └── inputs.h/c           # Input capture
    │   ├── handle_sound/
    │   │   └── sound.h/c            # Windows audio management
    │   └── utils/
    │       └── utils.h/c            # Utility functions
```

## Getting Started

### Quick Start (Pre-built Version)
The easiest way to play is to use the pre-built executable:

1. Download the entire `reverse_cct` folder (located inside the root `reverse_cct` directory) containing:
   - `reverse_cct.exe` - The executable file
   - `sounds/digits/` - Audio files required for the game
   - All necessary dependencies

2. Launch the game:
```
reverse_cct.exe
```
3. Start playing!

### Building from Source

#### Requirements
- GCC compiler
- Windows operating system (for winmm.lib)

#### Compilation
```
gcc -o reverse_cct main.c src/backend/data/structs.c src/backend/game_logic/game_logic.c \
    src/backend/game_logic/handle_inputs/inputs.c src/backend/game_logic/handle_sound/sound.c \
    src/backend/utils/utils.c -lwinmm
```

#### Execution
```
./reverse_cct
```

## Controls

- **Keys 0-9** : Enter your response (enter the units digit of your running sum)
- The game runs in an infinite loop; press `Ctrl+C` to exit

## Technologies Used

- **Language** : C
- **Audio API** : Windows Multimedia API (mmsystem.h)
- **Input Handling** : Windows Console API with `_kbhit()`
- **Timing** : Windows Sleep API
- **Platform** : Windows only

---

*This project implements a cognitive control training application that combines 2 tasks, scientifically designed to help with emotion regulation and impulse control.*