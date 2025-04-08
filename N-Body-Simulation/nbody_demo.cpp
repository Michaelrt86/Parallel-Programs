#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstdlib>  // For rand()

#define G 6.67430e-8    // Gravitational constant
#define DT 0.1          // Time step
#define NUM_BODIES 500  // Number of bodies (only change this number to scale up the computation)
#define NUM_STEPS 5000  // Number of simulation steps
#define WIDTH 1000.0    // Visualization width
#define HEIGHT 1000.0   // Visualization height
#define DEPTH 1000.0    // Visualization depth

struct Body {
    double x, y, z, vx, vy, vz, mass;
};

std::vector<Body> bodies(NUM_BODIES);
std::vector<std::tuple<double, double, double>> forces(NUM_BODIES);

void compute_forces() {
    int n = bodies.size();
    for (int i = 0; i < n; i++) {
        double fx = 0.0, fy = 0.0, fz = 0.0;
        for (int j = 0; j < n; j++) {
	    // calculate the forces based on the distance and mass between each particle pair
        }
        forces[i] = {fx, fy, fz};
    }
}

void update_positions() {
    for (int i = 0; i < bodies.size(); i++) {
        // Update velocities based on forces (Hint: this step involves forces[i], bodies[i].mass, and DT)
        
        // Update positions (Hint: this step involves forces[i], bodies[i].mass, and DT)
        
        // Take care of boundary conditions (bounce off the walls)
    }
}

void initialize_bodies() {
	// Initialize NUM_BODIES particles
}

void save_to_csv(std::ofstream &file, int step) {
    for (int i = 0; i < NUM_BODIES; i++) {
        file << step << "," << i << "," << bodies[i].x << "," << bodies[i].y << "," << bodies[i].z << "\n";
    }
}

void run_simulation() {
    std::ofstream file("nbody_output.csv");
    file << "step,id,x,y,z\n";

    for (int step = 0; step < NUM_STEPS; step++) {
        compute_forces();
        update_positions();
        save_to_csv(file, step);
    }

    file.close();
}

int main(int argc, char *argv[]) {
    initialize_bodies();
    run_simulation();
    std::cout << "Simulation complete. Data saved to nbody_output.csv\n";
    return 0;
}

