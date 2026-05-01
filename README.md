# Double Pendulum Simulation

A real-time, interactive physics simulation of a double pendulum system built with **C++** and the **raylib** graphics library. This project demonstrates chaotic motion through numerical integration of the equations of motion.

## Features

- **Lagrangian Mechanics:** Accurate calculation of angular acceleration for both pendulum arms.
- **Real-time Visualization:** Smooth 60 FPS rendering of the pendulum's motion.
- **Dynamic Path Tracing:** A "ghost" trail (GOLD color) follows the tip of the second pendulum to visualize its chaotic trajectory.
- **Randomized Initialization:** Each run starts with unique random angles to showcase how sensitive the system is to initial conditions.
- **Damping:** Includes a slight friction coefficient to simulate energy loss over time.

## Mathematical Overview

The simulation solves for the angular accelerations $\alpha_1$ and $\alpha_2$ (represented as `dd_phi1` and `dd_phi2` in the code) using the following system of differential equations:

$$\ddot{\theta_1} = \frac{-g(2m_1 + m_2)\sin\theta_1 - m_2g\sin(\theta_1 - 2\theta_2) - 2\sin(\theta_1 - \theta_2)m_2(\dot{\theta_2}^2L_2 + \dot{\theta_1}^2L_1\cos(\theta_1 - \theta_2))}{L_1(2m_1 + m_2 - m_2\cos(2\theta_1 - 2\theta_2))}$$

$$\ddot{\theta_2} = \frac{2\sin(\theta_1 - \theta_2)(\dot{\theta_1}^2L_1(m_1 + m_2) + g(m_1 + m_2)\cos\theta_1 + \dot{\theta_2}^2L_2m_2\cos(\theta_1 - \theta_2))}{L_2(2m_1 + m_2 - m_2\cos(2\theta_1 - 2\theta_2))}$$

## Prerequisites

To compile and run this project, you need:

- A C++ compiler (GCC, Clang, or MSVC)
- [raylib](https://www.raylib.com/) installed on your system.

## Building and Running

1. **Clone the repository:**

    ```bash
    git clone [https://github.com/yourusername/double-pendulum.git](https://github.com/onurvallor/double-pendulum.git)
    cd double-pendulum
    ```

2. **Compile the code:**
    Using `g++` as an example:

    ```bash
    g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o double_pendulum
    ```

    _(Note: Linking flags may vary depending on your OS. See [raylib's wiki](https://github.com/raysan5/raylib/wiki) for specifics.)_

3. **Execute:**

    ```bash
    ./double_pendulum
    ```

## Controls

- **ESC:** Close the simulation.
- **Window Close Button:** Exit the application.

## Configuration

You can easily modify the behavior of the simulation by adjusting the constants at the top of `main.cpp`:

| Variable      | Description                         | Default Value |
| :------------ | :---------------------------------- | :------------ |
| `GRAVITY`     | Strength of the gravitational pull  | `1`           |
| `L1` / `L2`   | Length of the first and second rods | `250`         |
| `MASS_RADIUS` | Visual size and mass of the weights | `10`          |
| `path.size()` | Length of the golden trail          | `100`         |

---

## License

This project is open-source and available under the [MIT License](LICENSE).
