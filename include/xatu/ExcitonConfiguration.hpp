#pragma once
#include "xatu/ConfigurationBase.hpp"
#include <armadillo>

namespace xatu {

/**
 * ExcitonConfiguration is a specialization of ConfigurationBase to parse
 * exciton configuration files. 
 */
class ExcitonConfiguration : public ConfigurationBase{

    struct configuration {
        // Simulation label
        std::string label;
        // Number of unit cells in the calculation
        int ncell;
        // Number of valence/conduction bands that are used in the exciton calculation.
        int nbands = 0;
        // Reduction factor of the BZ mesh. Defaults to 1.
        int submeshFactor = 1;
        // Specific bands that are used to compute the exciton spectrum.
        arma::ivec bands = {};
        // Center-of-mass momentum of the exciton.
        arma::rowvec Q = {0., 0., 0.};
        // Displacement vector of the center of the BZ mesh.
        arma::rowvec shift;
        // Cutoff to be used 
        double cutoff;
        // Dielectric constants
        arma::vec eps = {};
        // Screening length
        double r0;
        // Thickness of layer
        double d;
        // Calculation mode (either 'realspace' or 'reciprocalspace')
        std::string mode = "realspace";
        // Flag to compute the exciton spectrum with exchange
        bool exchange = false;
        // Scissor cut to correct the bandgap
        double scissor = 0.0;
        // Number of reciprocal vectors to use in reciprocal space calculation
        int nReciprocalVectors = 0;
        // Interaction type (Keldysh or Coulomb)
        std::string interactionType = "keldysh";
    };

    public:
        configuration excitonInfo;
    
    public:
        ExcitonConfiguration();
        ExcitonConfiguration(std::string);
    
    private:
        virtual void parseContent();
        void checkContentCoherence();
};

}