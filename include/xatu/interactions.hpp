#include <armadillo>
#include <complex>

#include "xatu.hpp"


namespace xatu {

    // ------ Potentials ------

    /* Keldysh potential */
    double keldysh(double, double, double, double, double, double);
    void STVH0(double, double*);  // Auxiliary routine for Struve function

    /* Coulomb potential */
    double coulomb(double, double, double, double);

    /* Keldysh potential FT */
    double keldyshFT(const arma::rowvec&, double, double, double, double, int, double );

    /* Coulomb potential FT */
    double coulombFT(const arma::rowvec& q, double eps_r, double unitCellArea, int totalCells, double eps);

    // ------ Interaction matrix elements ------

    /* Real-space interaction */
    std::complex<double> keldyshMotifFourierTransform(const arma::rowvec& firstAtom, const arma::rowvec& secondAtom,
                                                      const arma::rowvec& k, const arma::mat& cells, int totalCells,
                                                      double r0, double eps_s, double eps_m, double cutoff, double a);
    std::complex<double> coulombMotifFourierTransform(const arma::rowvec& firstAtom, const arma::rowvec& secondAtom,
                                                      const arma::rowvec& k, const arma::mat& cells, int totalCells,
                                                      double eps_r, double cutoff, double a);
    arma::cx_mat motifFTMatrix(const arma::rowvec&, const arma::mat&, const arma::mat&);
    arma::cx_mat extendMotifFT(const arma::cx_mat&, int, const arma::mat&, const arma::urowvec&);
    arma::cx_vec sumStateOverOrbitals(const arma::rowvec&, const arma::urowvec&);

    std::complex<double> realSpaceInteractionElement(const arma::cx_vec&,
                                                     const arma::cx_vec&,
                                                     const arma::cx_vec&,
                                                     const arma::cx_vec&,
                                                     const arma::cx_mat&,
                                                     const arma::mat&,
                                                     const arma::urowvec&);

    /* Reciprocal space interaction */
    std::complex<double> blochCoherenceFactor(const arma::cx_vec&, const arma::cx_vec&,
                                              const arma::rowvec&, const arma::rowvec&,
                                              const arma::rowvec&, const arma::mat&, const arma::urowvec&);

    std::complex<double> reciprocalSpaceInteractionElement(const arma::cx_vec&,
                                                           const arma::cx_vec&,
                                                           const arma::cx_vec&,
                                                           const arma::cx_vec&,
                                                           const arma::rowvec&,
                                                           const arma::rowvec&,
                                                           const arma::rowvec&,
                                                           const arma::rowvec&,
                                                           int,
                                                           const arma::mat&);

    
}