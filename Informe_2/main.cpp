#include <bits/stdc++.h>
#include "libre.cpp"

int main()
{

    //std::cout << fib_rec_dou(100) << std::endl;
    //std::cout << fib_it_rec(1073741824) << std::endl;
    /*
    double b = 1048576;
    double it = fib_it(1073741824);
    double rc = fib_rec(1073741824);

    
    puts("iterative");
    std::cout << it % b << std::endl;

    puts("Recursive");
    std::cout << rc % b << std::endl;
    std::cout << fib_it(100);
    */

    /*
    //part 1 
    srand((unsigned)time(0));

    //given values
    std::vector<int> n = {256, 512, 1024, 2048, 
                          4096, 8192, 16384, 32768, 
                          65536, 131072, 262144, 524288,
                          1048576};
    int n_vecs = 200;

    //answers
    std::vector<double> average;
    std::vector<double> log_res;

    //exe()
    for (auto i = 0; i < n.size(); ++i)
    {
        //temp values
        std::vector<int> a(n[i]);
        double ln_valu = 0;
        double tmp_avg = 0;

        //exe per data 0,1,2 ... n from (n)
        for (auto j = 0; j < n_vecs; ++j)
        {
            replace(n[i], a);
            tmp_avg += get_max(a);
        }

        //obtain answers (ln(a[i])+1) .. average_n of a[i]
        tmp_avg = tmp_avg / n_vecs;
        ln_valu = log(a[i]) + 1;

        //save values
        average.push_back(tmp_avg);
        log_res.push_back(ln_valu);
    }

    //show answers
    std::cout << std::endl;
    print_vec(n);
    print_vec(average);
    print_vec(log_res);
    //par1 
    */
    return EXIT_SUCCESS;
}