// Includes
#include <iostream>

// includes CUDA
#include <cuda_runtime.h>

// CUDA runtime
#include <cuda_runtime.h>

// Helper functions and utilities to work with CUDA
#include <helper_cuda.h>

// Code GPU
__global__ void copymat_device(const float* A, float* B)
{
	// A compléter
}


// Code CPU
void genmat(float *A, int n)
{
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			A[i*n + j] = rand()/(float) RAND_MAX;
}


float verify(const float *A, const float* B, int n)
{
	float error = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			error = std::max(error, abs(A[i*n + j] - B[i*n + j]));

	return error;
}


int main(int argc, char** argv)
{
	printf("Copie de  matrice\n");
	int n = 4096;
	size_t size = n*n*sizeof(float);

	// Matrices CPU
	float *h_A = nullptr, *h_B = nullptr;
	// Matrices GPU
	float *d_A = nullptr, *d_B = nullptr;

	// Allocatation des vecteurs dans la mémoire CPU
	h_A = new float[n];
	h_B = new float[n];

	// Allocation des vecteurs dans la mémoire GPU
	// A compléter

	// Initialisation de la matrice A
	genmat(h_A, n);

	// Copie de la matrice A dans la mémoire GPU
	checkCudaErrors(cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice));

	// Definition de la taille des blocs et de la grille
	dim3 threadsPerBlock(// A compléter);
	dim3 numBlocks(// A compléter);

	copymat_device<<<numBlocks, threadsPerBlock>>>(d_A, d_B);
    checkCudaErrors(cudaPeekAtLastError());
    checkCudaErrors(cudaDeviceSynchronize());

	// Copie du résultat
	checkCudaErrors(cudaMemcpy(h_B, d_B, size, cudaMemcpyDeviceToHost));

	// Verification
	printf("Erreur max: %e\n", verify(h_A, h_B, n));

	// Timing
	cudaEvent_t start, stop;
	checkCudaErrors(cudaEventCreate(&start));
	checkCudaErrors(cudaEventCreate(&stop));

	const int nb = 10;
	checkCudaErrors(cudaEventRecord(start, 0));
	for (int i = 0; i < nb; i++)
		copymat_device<<<numBlocks, threadsPerBlock>>>(d_A, d_B);
	checkCudaErrors(cudaEventRecord(stop, 0));
	checkCudaErrors(cudaEventSynchronize(stop));
	float t_ms;
	checkCudaErrors(cudaEventElapsedTime(&t_ms, start, stop));
	t_ms /= nb;

	printf("Temps d'exécution du Kernel : %e (ms)\n", t_ms);
	printf("Bande passante GPU: %e GO/s\n", // A compléter);

	// Deallocation de la memoire GPU
	// A compléter

	// Deallocation de la memoire CPU
	delete [] h_a;
	delete [] h_b;
}
