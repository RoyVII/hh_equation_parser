#include "nm_gui_komendantov_kononenko_1996.h"
#include "ui_nm_gui_komendantov_kononenko_1996.h"

NM_GUI_Komendantov_Kononenko_1996::NM_GUI_Komendantov_Kononenko_1996(clamp_args * args, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::NM_GUI_Komendantov_Kononenko_1996)
{
	this->settings = new QSettings("RTHybrid", "NM_Komendantov_Kononenko_1996");
	this->args = args;
	ui->setupUi(this);
	loadSettings();
}

NM_GUI_Komendantov_Kononenko_1996::~NM_GUI_Komendantov_Kononenko_1996(){
	 delete ui;
}

void NM_GUI_Komendantov_Kononenko_1996::on_pushButton_accept_clicked() {
	args->vars = (double*) malloc (sizeof(double) * 8);
	args->params = (double *) malloc (sizeof(double) * 20);

	args->vars[NM_KOMENDANTOV_KONONENKO_1996_V] = ui->doubleSpinBox_V->value();
	args->vars[NM_KOMENDANTOV_KONONENKO_1996_M_B] = ui->doubleSpinBox_m_b->value();
	args->vars[NM_KOMENDANTOV_KONONENKO_1996_H_B] = ui->doubleSpinBox_h_b->value();
	args->vars[NM_KOMENDANTOV_KONONENKO_1996_M] = ui->doubleSpinBox_m->value();
	args->vars[NM_KOMENDANTOV_KONONENKO_1996_H] = ui->doubleSpinBox_h->value();
	args->vars[NM_KOMENDANTOV_KONONENKO_1996_N] = ui->doubleSpinBox_n->value();
	args->vars[NM_KOMENDANTOV_KONONENKO_1996_M_CA] = ui->doubleSpinBox_m_ca->value();
	args->vars[NM_KOMENDANTOV_KONONENKO_1996_CA] = ui->doubleSpinBox_Ca->value();

	args->params[NM_KOMENDANTOV_KONONENKO_1996_I] = ui->doubleSpinBox_i->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_SYN] = ui->doubleSpinBox_syn->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_CM] = ui->doubleSpinBox_Cm->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_NA_V] = ui->doubleSpinBox_g_na_v->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_V_NA] = ui->doubleSpinBox_V_na->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_K] = ui->doubleSpinBox_g_k->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_V_K] = ui->doubleSpinBox_V_k->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_NA] = ui->doubleSpinBox_g_na->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_B] = ui->doubleSpinBox_g_b->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_V_B] = ui->doubleSpinBox_V_b->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_NA_TTX] = ui->doubleSpinBox_g_na_ttx->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_K_TEA] = ui->doubleSpinBox_g_k_tea->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_CA] = ui->doubleSpinBox_g_ca->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_V_CA] = ui->doubleSpinBox_V_ca->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_G_CA_CA] = ui->doubleSpinBox_g_ca_ca->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_K_BETA] = ui->doubleSpinBox_k_beta->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_BETA] = ui->doubleSpinBox_beta->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_RHO] = ui->doubleSpinBox_rho->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_K_S] = ui->doubleSpinBox_k_s->value();
	args->params[NM_KOMENDANTOV_KONONENKO_1996_DT] = ui->comboBoxIntegrationMethod->currentIndex();

	saveSettings();
	this->close();
}

void NM_GUI_Komendantov_Kononenko_1996::saveSettings() {
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_V", ui->doubleSpinBox_V->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_M_B", ui->doubleSpinBox_m_b->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_H_B", ui->doubleSpinBox_h_b->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_M", ui->doubleSpinBox_m->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_H", ui->doubleSpinBox_h->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_N", ui->doubleSpinBox_n->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_M_CA", ui->doubleSpinBox_m_ca->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_CA", ui->doubleSpinBox_Ca->value());

	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_I", ui->doubleSpinBox_i->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_SYN", ui->doubleSpinBox_syn->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_CM", ui->doubleSpinBox_Cm->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_NA_V", ui->doubleSpinBox_g_na_v->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_V_NA", ui->doubleSpinBox_V_na->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_K", ui->doubleSpinBox_g_k->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_V_K", ui->doubleSpinBox_V_k->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_NA", ui->doubleSpinBox_g_na->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_B", ui->doubleSpinBox_g_b->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_V_B", ui->doubleSpinBox_V_b->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_NA_TTX", ui->doubleSpinBox_g_na_ttx->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_K_TEA", ui->doubleSpinBox_g_k_tea->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_CA", ui->doubleSpinBox_g_ca->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_V_CA", ui->doubleSpinBox_V_ca->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_G_CA_CA", ui->doubleSpinBox_g_ca_ca->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_K_BETA", ui->doubleSpinBox_k_beta->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_BETA", ui->doubleSpinBox_beta->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_RHO", ui->doubleSpinBox_rho->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_K_S", ui->doubleSpinBox_k_s->value());
	settings->setValue("NM_KOMENDANTOV_KONONENKO_1996_DT", ui->comboBoxIntegrationMethod->currentIndex());
}

void NM_GUI_Komendantov_Kononenko_1996::loadSettings() {
	if (settings->value("NM_KOMENDANTOV_KONONENKO_1996_DT", -1).toInt() == -1) return; //No settings saved yet

	ui->doubleSpinBox_V->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_V").toDouble());
	ui->doubleSpinBox_m_b->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_M_B").toDouble());
	ui->doubleSpinBox_h_b->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_H_B").toDouble());
	ui->doubleSpinBox_m->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_M").toDouble());
	ui->doubleSpinBox_h->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_H").toDouble());
	ui->doubleSpinBox_n->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_N").toDouble());
	ui->doubleSpinBox_m_ca->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_M_CA").toDouble());
	ui->doubleSpinBox_Ca->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_CA").toDouble());

	ui->doubleSpinBox_i->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_I").toDouble());
	ui->doubleSpinBox_syn->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_SYN").toDouble());
	ui->doubleSpinBox_Cm->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_CM").toDouble());
	ui->doubleSpinBox_g_na_v->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_NA_V").toDouble());
	ui->doubleSpinBox_V_na->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_V_NA").toDouble());
	ui->doubleSpinBox_g_k->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_K").toDouble());
	ui->doubleSpinBox_V_k->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_V_K").toDouble());
	ui->doubleSpinBox_g_na->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_NA").toDouble());
	ui->doubleSpinBox_g_b->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_B").toDouble());
	ui->doubleSpinBox_V_b->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_V_B").toDouble());
	ui->doubleSpinBox_g_na_ttx->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_NA_TTX").toDouble());
	ui->doubleSpinBox_g_k_tea->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_K_TEA").toDouble());
	ui->doubleSpinBox_g_ca->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_CA").toDouble());
	ui->doubleSpinBox_V_ca->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_V_CA").toDouble());
	ui->doubleSpinBox_g_ca_ca->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_G_CA_CA").toDouble());
	ui->doubleSpinBox_k_beta->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_K_BETA").toDouble());
	ui->doubleSpinBox_beta->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_BETA").toDouble());
	ui->doubleSpinBox_rho->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_RHO").toDouble());
	ui->doubleSpinBox_k_s->setValue(settings->value("NM_KOMENDANTOV_KONONENKO_1996_K_S").toDouble());
	ui->comboBoxIntegrationMethod->setCurrentIndex(settings->value("NM_KOMENDANTOV_KONONENKO_1996_DT").toInt());
}