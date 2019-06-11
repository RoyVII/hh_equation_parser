#include "nm_komendantov_kononenko_1996.h"
#include "../../integration_methods.h"
#include "../neuron_models_aux_functions.h"

/**
 * @file nm_komendantov_kononenko_1996.h
 * @brief Source file for the Komendantov_Kononenko_1996 model functions.
 */

/** @name Komendantov_Kononenko_1996
 * Komendantov_Kononenko_1996 neuron model.
 */
///@{

double nm_komendantov_kononenko_1996_i_na_v (double * vars, double * params);
double nm_komendantov_kononenko_1996_i_k (double * vars, double * params);
double nm_komendantov_kononenko_1996_i_na (double * vars, double * params);
double nm_komendantov_kononenko_1996_i_b (double * vars, double * params);
double nm_komendantov_kononenko_1996_i_na_ttx (double * vars, double * params);
double nm_komendantov_kononenko_1996_i_k_tea (double * vars, double * params);
double nm_komendantov_kononenko_1996_i_ca (double * vars, double * params);
double nm_komendantov_kononenko_1996_i_ca_ca (double * vars, double * params);
double nm_komendantov_kononenko_1996_V (double * vars, double * params);
double nm_komendantov_kononenko_1996_m_b (double * vars, double * params);
double nm_komendantov_kononenko_1996_h_b (double * vars, double * params);
double nm_komendantov_kononenko_1996_m (double * vars, double * params);
double nm_komendantov_kononenko_1996_h (double * vars, double * params);
double nm_komendantov_kononenko_1996_n (double * vars, double * params);
double nm_komendantov_kononenko_1996_m_ca (double * vars, double * params);
double nm_komendantov_kononenko_1996_Ca (double * vars, double * params);
double nm_komendantov_kononenko_1996_set_pts_burst (double pts_live, neuron_model * nm);


double nm_komendantov_kononenko_1996_V (double * vars, double * params) {
	double i_na_ttx = nm_komendantov_kononenko_1996_i_na_ttx(vars, params);
	double i_k_tea = nm_komendantov_kononenko_1996_i_k_tea(vars, params);
	double i_k = nm_komendantov_kononenko_1996_i_k(vars, params);
	double i_na = nm_komendantov_kononenko_1996_i_na(vars, params);
	double i_na_v = nm_komendantov_kononenko_1996_i_na_v(vars, params);
	double i_b = nm_komendantov_kononenko_1996_i_b(vars, params);
	double i_ca = nm_komendantov_kononenko_1996_i_ca(vars, params);
	double i_ca_ca = nm_komendantov_kononenko_1996_i_ca_ca(vars, params);
	return (-(i_na_ttx + i_k_tea + i_k + i_na + i_na_v + i_b + i_ca + i_ca_ca) + params[NM_KOMENDANTOV_KONONENKO_1996_I] - params[NM_KOMENDANTOV_KONONENKO_1996_SYN]) / params[NM_KOMENDANTOV_KONONENKO_1996_CM];
}

double nm_komendantov_kononenko_1996_i_na_v (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_NA_V] * (1.000000 / (1.000000 + exp(-0.200000 * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] + 45.000000)))) * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_NA]);
}

double nm_komendantov_kononenko_1996_i_k (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_K] * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_K]);
}

double nm_komendantov_kononenko_1996_i_na (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_NA] * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_NA]);
}

double nm_komendantov_kononenko_1996_i_b (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_B] * vars[NM_KOMENDANTOV_KONONENKO_1996_M_B] * vars[NM_KOMENDANTOV_KONONENKO_1996_H_B] * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_B]);
}

double nm_komendantov_kononenko_1996_m_b (double * vars, double * params) {
	return (1.000000 / (1.000000 + exp(0.400000 * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] + 34.000000))) - vars[NM_KOMENDANTOV_KONONENKO_1996_M_B]) / 0.050000;
}

double nm_komendantov_kononenko_1996_h_b (double * vars, double * params) {
	return (1.000000 / (1.000000 + exp(-0.550000 * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] + 43.000000))) - vars[NM_KOMENDANTOV_KONONENKO_1996_H_B]) / 1.500000;
}

double nm_komendantov_kononenko_1996_i_na_ttx (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_NA_TTX] * vars[NM_KOMENDANTOV_KONONENKO_1996_M]*vars[NM_KOMENDANTOV_KONONENKO_1996_M]*vars[NM_KOMENDANTOV_KONONENKO_1996_M] * vars[NM_KOMENDANTOV_KONONENKO_1996_H] * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_NA]);
}

double nm_komendantov_kononenko_1996_i_k_tea (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_K_TEA] * vars[NM_KOMENDANTOV_KONONENKO_1996_N]*vars[NM_KOMENDANTOV_KONONENKO_1996_N]*vars[NM_KOMENDANTOV_KONONENKO_1996_N]*vars[NM_KOMENDANTOV_KONONENKO_1996_N] * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_K]);
}

double nm_komendantov_kononenko_1996_m (double * vars, double * params) {
	return (1.000000 / (1.000000 + exp(-0.400000 * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] + 31.000000))) - vars[NM_KOMENDANTOV_KONONENKO_1996_M]) / 0.000500;
}

double nm_komendantov_kononenko_1996_h (double * vars, double * params) {
	return (1.000000 / (1.000000 + exp(0.250000 * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] + 45.000000))) - vars[NM_KOMENDANTOV_KONONENKO_1996_H]) / 0.010000;
}

double nm_komendantov_kononenko_1996_n (double * vars, double * params) {
	return (1.000000 / (1.000000 + exp(-0.180000 * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] + 25.000000))) - vars[NM_KOMENDANTOV_KONONENKO_1996_N]) / 0.015000;
}

double nm_komendantov_kononenko_1996_i_ca (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_CA] * vars[NM_KOMENDANTOV_KONONENKO_1996_M_CA]*vars[NM_KOMENDANTOV_KONONENKO_1996_M_CA] * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_CA]);
}

double nm_komendantov_kononenko_1996_m_ca (double * vars, double * params) {
	return (1.000000 / (1.000000 + exp(-0.200000 * vars[NM_KOMENDANTOV_KONONENKO_1996_V])) - vars[NM_KOMENDANTOV_KONONENKO_1996_M_CA]) / 0.010000;
}

double nm_komendantov_kononenko_1996_i_ca_ca (double * vars, double * params) {
	return params[NM_KOMENDANTOV_KONONENKO_1996_G_CA_CA] * (1.000000 / (1.000000 + exp(-0.060000 * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] + 45.000000)))) * (1.000000 / (1.000000 + exp(params[NM_KOMENDANTOV_KONONENKO_1996_K_BETA] * (vars[NM_KOMENDANTOV_KONONENKO_1996_CA] - params[NM_KOMENDANTOV_KONONENKO_1996_BETA])))) * (vars[NM_KOMENDANTOV_KONONENKO_1996_V] - params[NM_KOMENDANTOV_KONONENKO_1996_V_CA]);
}

double nm_komendantov_kononenko_1996_Ca (double * vars, double * params) {
	double i_ca = nm_komendantov_kononenko_1996_i_ca(vars, params);
	return params[NM_KOMENDANTOV_KONONENKO_1996_RHO] * ((-i_ca / 808.310846) - (params[NM_KOMENDANTOV_KONONENKO_1996_K_S] * vars[NM_KOMENDANTOV_KONONENKO_1996_CA]));
}

/**
 * @brief Komendantov_Kononenko_1996 neuron model differential equations.
 * @param[in] vars Neuron model variables
 * @param[out] ret Return values array
 * @param[in] params Neuron models parameters
 * @param[in] syn Synapse input current value
 */

void nm_komendantov_kononenko_1996_f (double * vars, double * ret, double * params, double syn) {
	params[NM_KOMENDANTOV_KONONENKO_1996_SYN] = syn;

	ret[NM_KOMENDANTOV_KONONENKO_1996_V] = nm_komendantov_kononenko_1996_V(vars, params);
	ret[NM_KOMENDANTOV_KONONENKO_1996_M_B] = nm_komendantov_kononenko_1996_m_b(vars, params);
	ret[NM_KOMENDANTOV_KONONENKO_1996_H_B] = nm_komendantov_kononenko_1996_h_b(vars, params);
	ret[NM_KOMENDANTOV_KONONENKO_1996_M] = nm_komendantov_kononenko_1996_m(vars, params);
	ret[NM_KOMENDANTOV_KONONENKO_1996_H] = nm_komendantov_kononenko_1996_h(vars, params);
	ret[NM_KOMENDANTOV_KONONENKO_1996_N] = nm_komendantov_kononenko_1996_n(vars, params);
	ret[NM_KOMENDANTOV_KONONENKO_1996_M_CA] = nm_komendantov_kononenko_1996_m_ca(vars, params);
	ret[NM_KOMENDANTOV_KONONENKO_1996_CA] = nm_komendantov_kononenko_1996_Ca(vars, params);
}

/**
 * @brief Komendantov_Kononenko_1996 neuron model.
 * @param[in] nm Neuron model structure
 * @param[in] syn Synapse input current value
 */

void nm_komendantov_kononenko_1996 (neuron_model nm, double syn) {
	nm.method(nm_komendantov_kononenko_1996_f, nm.dim, nm.params[NM_KOMENDANTOV_KONONENKO_1996_DT], nm.vars, nm.params, syn);
	return;
}

/**
 * @brief Initializes Komendantov_Kononenko_1996 neuron model.
 * @param[in] nm Pointer to the neuron model structure
 * @param[in] vars Array with the initial values of the model variables
 * @param[in] params Array with the values of the mode parameters
 */

void nm_komendantov_kononenko_1996_init (neuron_model * nm, double * vars, double * params) {
	nm->dim = 8;
	nm->vars = (double *) malloc (sizeof(double) * nm->dim);
	copy_1d_array(vars, nm->vars, nm->dim);

	nm->n_params = 20;
	nm->params = (double *) malloc (sizeof(double) * nm->n_params);
	copy_1d_array(params, nm->params, nm->n_params);

	nm->max = 55;
	nm->min = -65;
	nm->pts_burst = -1.0;

	nm->func = &nm_komendantov_kononenko_1996;
	//nm->set_pts_burst = &nm_komendantov_kononenko_1996_set_pts_burst;
	nm->method = integration_method_selector(params[NM_KOMENDANTOV_KONONENKO_1996_DT]);

	return;
}

