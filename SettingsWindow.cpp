#include <QDebug>
#include <QColordialog>
#include <QPalette>
#include <QColor>
#include <QRgb>

#include "SettingsWindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SettingsWindow)
{
	ui->setupUi(this);
	ui->lineEditTicketSectionSeparatorChar->setMaxLength(1);
	
	QPalette palette = ui->textEditCharColor->palette();
	palette.setColor(QPalette::Base, QColor::fromRgb(0, 0, 255));
	ui->textEditCharColor->setPalette(palette);
}

SettingsWindow::~SettingsWindow()
{
	delete ui;
}

QString SettingsWindow::getRestaurantName()
{
	return ui->lineEditRestaurantName->text();
}

QString SettingsWindow::getRestaurantAddress()
{
	return ui->lineEditRestaurantAddress->text();
}

QString SettingsWindow::getFooterMessage()
{
	return ui->lineEditFooterMessage->text();
}

QChar SettingsWindow::getTicketSectionCharSeparator()
{
	return ui->lineEditTicketSectionSeparatorChar->text().at(0);
}

void SettingsWindow::setRestaurantName(QString restaurantName)
{
	this->ui->lineEditRestaurantName->setText(restaurantName);
}

void SettingsWindow::setRestaurantAddress(QString restaurantAddress)
{
	this->ui->lineEditRestaurantAddress->setText(restaurantAddress);
}

void SettingsWindow::setFooterMessage(QString footerMessage)
{
	this->ui->lineEditFooterMessage->setText(footerMessage);
}

void SettingsWindow::setTicketSectionCharSeparator(QChar c)
{
	this->ui->lineEditTicketSectionSeparatorChar->setText(c);
}

void SettingsWindow::on_checkBoxFullScreen_stateChanged(int state)
{
	if (this->ui->checkBoxFullScreen->isChecked())
	{
		qDebug() << "Fullscreen application";
	}
	else
	{
		qDebug() << "Maximized application";
	}
}

bool SettingsWindow::isFullScreen()
{
	return this->ui->checkBoxFullScreen->isChecked();
}

void SettingsWindow::setFullScreen(bool value)
{
	this->ui->checkBoxFullScreen->setChecked(value);
}

void SettingsWindow::on_pushButtonTicketCharColor_clicked()
{
	qDebug() << "Change ticket char color";
	setTicketCharColor(QColorDialog::getColor());
}

void SettingsWindow::setTicketCharColor(QColor color)
{
	this->ui->textEditCharColor->setPalette(QPalette(color));
}

QColor SettingsWindow::getTicketCharColor()
{
	return ticketCharColor;
}
