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
 
 ### Example of how it looks after Dimensionality reduction by 50%
 
<img width="479" height="246" alt="Screenshot 2025-08-20 185458" src="https://github.com/user-attachments/assets/52f5e632-53e5-44cc-b396-e7f131a8507d" />



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
```
This produces two main executables:

- `train` — trains either classifier or autoencoder based on JSON config  
- `dimensionality_reducer` — applies the encoder portion of a trained autoencoder to new data

### Configuration

Copy the `.dist` files and update paths:
cp ../config/train.json.dist ../config/train.json
cp ../config/autoencoder.json.dist ../config/autoencoder.json

Edit `config/train.json` to point at your training CSV, labels CSV, and desired weights output.  
Edit `config/autoencoder.json` to set input CSV, weights file, and network topology.

### Train as Classifier
```bash
./train ../config/train.json
```
Output: training progress per epoch, final weights saved to config.weightsFile


### Train as Autoencoder (Dimensionality Reduction)
```bash
./train ../config/autoencoder.json
```

### Extract Encoded Features
```bash
./dimensionality_reducer ../config/autoencoder.json path/to/data.csv > reduced_features.csv
```

Each line of `reduced_features.csv` is the bottleneck-layer representation for one input.

---

## License

This project is released under the MIT License. Feel free to adapt and extend!

---

Harness the power of a flexible, memory-safe C++ neural network—train classifiers and uncover compact representations with the same codebase. Enjoy!


