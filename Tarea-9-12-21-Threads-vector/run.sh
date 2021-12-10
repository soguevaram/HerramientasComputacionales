N=400000000

source $HOME/Repos/spack/share/spack/setup-env.sh
spack load openblas
g++ threads.cpp -pthread
for nthreads in $(seq 1 16); do
    ./a.out  ${N} ${nthreads} 2>/dev//null
done > datos.txt
spack unload openblas
