# Artificial Neural Network Improved
An **improved C++** implementation of a feed-forward neural network that can be used both as  
1. A **deep-learning classifier** on datasets (e.g., Fashion-MNIST), and  
2. A **dimensionality reducer** via its autoencoder architecture.
This project features robust pointer management to prevent memory leaks, leverages JSON for configuration, and compiles via CMake.
---
## Key Features
- **Dual Purpose**  
  - **Classifier:** Train on input/label CSVs to learn classification tasks.  
  - **Autoencoder:** Train with input==target to learn compressed representations (bottleneck layer for dimensionality reduction).
 
 ### Example of how it looks after Dimensionality reduction by 786 px to 30 px
 
<img width="485" height="252" alt="image" src="https://github.com/user-attachments/assets/6eed3b1f-e580-46c3-9d05-94c3a5983bc6" />

### Speed of training reduced by >50%

<img width="485" height="252" alt="image" src = "https://github.com/user-attachments/assets/190daeda-65ab-433c-bb78-b14fe9278aed" />

### How the reconstructed images performed with comparison to original images

<img width="485" height="252" alt="image" src="https://github.com/user-attachments/assets/aa2d85ef-c8fc-41b2-8583-c64fe83241d6" />

- **C++ Implementation**  
  - Modern C++14 code, single-header JSON parsing (nlohmann/json).  
  - Custom `Matrix`, `Layer`, and `Neuron` classes for core operations.  
  - Explicit pointer ownership; every `new` has a matching `delete`.
- **Configurable via JSON**  
  - `config/train.json` for classifier training.  
  - `config/autoencoder.json` for autoencoder training / dimensionality reduction.
- **Memory Safety**  
  - Matrices and layers allocated on the heap but always freed.  
  - No global static data, no leaks, no use of raw arrays.
- **Parallel & Threaded Flags**  
  - Compiles with OpenMP and pthread flags (`-fopenmp -pthread`).
---
---
## Getting Started
### Prerequisites
- A C++14-capable compiler (GCC ≥ 5.0, Clang, MSVC)  
- CMake ≥ 3.10  
- OpenMP (optional, for parallel matrix ops)  
- A CSV dataset (e.g., Fashion-MNIST converted to CSV)
## 🚀 Build & Run Instructions
### 1. Prerequisites
- Install **CMake** (https://cmake.org/download/)
- Install **MinGW-w64** (make sure `g++` is in your PATH)
- Clone this repository
  ```bash
  git clone https://github.com/arshamakhtar/Artificial_Neural_Network-Improved.git
### 2. Build the project
Open terminal / PowerShell in the project root directory and run:
```bash
# Create a build directory
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```
This produces two main executables:
