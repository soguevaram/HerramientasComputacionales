MSIZE=4000
REPS=10
nthreads=12

# First section: running only with eigen
g++ -fopenmp -O3  eigen-matmul.cpp -o eigen.x
for nthreads in $(seq 1 16); do
    echo -n "${nthreads}  ";
    OMP_NUM_THREADS=${nthreads} ./eigen.x ${MSIZE} ${REPS} 2>/dev//null
done > data_eigen.txt

# Second section: running with blas
source $HOME/Repos/spack/share/spack/setup-env.sh
spack load openblas
g++ -fopenmp -O3 -I $CMAKE_PREFIX_PATH/include -L $CMAKE_PREFIX_PATH/lib  eigen-matmul.cpp -DEIGEN_USE_BLAS -lopenblas -o eigen_blas.x
for nthreads in $(seq 1 16); do
    echo -n "${nthreads}  ";
    OMP_NUM_THREADS=${nthreads} ./eigen_blas.x ${MSIZE} ${REPS} 2>/dev//null
done > eigen_blas.txt
spack unload openblas
