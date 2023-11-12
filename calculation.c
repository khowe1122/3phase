#include <stdio.h>
#include <math.h>
#include <fftw3.h>

#define DATA_LENGTH 20
#define n_harmonic 5

// voltage data arrays
float Va[DATA_LENGTH] = {
    156.63, 246.59, 294.72, 305.51, 300.66,
    268.03, 204.18, 125.41, 42.954, -48.322,
    -154.08, -243.95, -293.12, -303.09, -297.98,
    -264.13, -202.1, -122.25, -39.893, 51.818
};

float Vb[DATA_LENGTH] = {
    -308.4, -280.19, -240.66, -186.6, -99.744,
    -0.54547, 92.853, 181.46, 262.05, 312.39,
    311.44, 283.76, 245.04, 188.62, 102.16,
    2.9662, -89.395, -176.17, -259.16, -309.96
};

float Vc[DATA_LENGTH] = {
    156.11, 82.694, -21.783, -128.37, -213.06,
    -269.49, -309.58, -313.4, -273.73, -214.81,
    -154.29, -79.64, 24.679, 132.16, 216.63,
    274.14, 311.11, 315.76, 276.27, 216.22
};

// results
typedef struct _FrequencyPhase {
    float F_est;
    float Theta_est;
} FrequencyPhase;

typedef struct _Harmonics {
    float harmonics[n_harmonic];
} Harmonics;

typedef struct _DDATA {
    float *in_a;
    float *in_b;
    float *in_c;
    FrequencyPhase F_Theta[3];
    Harmonics harmonic_info[3];
    float Ts;
    float Kc1; // Kc are controller gains
    float Kc2; // choose your controller and
    float Kc3; // gains accordingly to get satisfied result
} DDATA;

void estimateFrequencyAndTheta(DDATA *data, int dataSize) {
// Implementation for estimating frequency and theta
// using signal processing techniques like Fast Fourier Transform (FFT)
    for (int phase = 0; phase < 3; phase++) {
        float *input;
        if (phase == 0) input = data->in_a;
        else if (phase == 1) input = data->in_b;
        else input = data->in_c;

        // Calculate the frequency assuming freq is the result
        float freq;
        data->F_Theta[phase].F_est = freq;

        // Calculate the angle assuming ang is the result
        float ang;
        data->F_Theta[phase].Theta_est = ang;
        printf("Estimated frequency for Phase %c: %.2f Hz, Theta_est: %.2f\n", 'A' + phase, data.F_Theta[phase].F_est, data.F_Theta[phase].Theta_est);
        printf("\n");
    }
}

void calculateHarmonicsAmplitude(DDATA *data, int dataSize) {
// Implementation for getting harmonic amplitudes
// using signal processing techniques like Fast Fourier Transform (FFT)
    for (int phase = 0; phase < 3; phase++) {
        float *input;
        if (phase == 0) input = data->in_a;
        else if (phase == 1) input = data->in_b;
        else input = data->in_c;

        printf("Harmonics amplitudes for Phase %c: ", 'A' + phase);
        for (int harmonic = 0; harmonic < n_harmonic; harmonic++) {
            // calculate the amplitudes 
            float amp;
            data->harmonic_info[phase].harmonics[harmonic] = amp;
            printf("%.2f ", data.harmonic_info[phase].harmonics[harmonic]);
        }
        printf("\n");
    }
    }
}

int main() {
    DDATA data = {
        .in_a = Va,
        .in_b = Vb,
        .in_c = Vc,
        .Ts = 0.001 // Assuming a sampling time of 1 ms
    };
    estimateFrequencyAndTheta(&data, DATA_LENGTH);
    calculateHarmonicsAmplitude(&data, DATA_LENGTH);
    }
    return 0;
}
