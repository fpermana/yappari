/* Copyright 2013 Naikel Aparicio. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL EELI REILIN OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation
 * are those of the author and should not be interpreted as representing
 * official policies, either expressed or implied, of the copyright holder.
 */

#include <QMessageBox>

#include "voiceregistrationwidget.h"
#include "ui_voiceregistrationwidget.h"

VoiceRegistrationWidget::VoiceRegistrationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VoiceRegistrationWidget)
{
    ui->setupUi(this);

    connect(ui->callButton,SIGNAL(clicked()),this,SLOT(callButtonPressed()));
    connect(ui->OKButton,SIGNAL(clicked()),this,SLOT(okButtonPressed()));
}

VoiceRegistrationWidget::~VoiceRegistrationWidget()
{
    delete ui;
}

void VoiceRegistrationWidget::callButtonPressed()
{
    emit requestCall();
}


void VoiceRegistrationWidget::okButtonPressed()
{
    QString code = ui->codeLineEdit->text();

    if (code.length() != 6)
    {
        QMessageBox msg(this);

        msg.setText("You have entered an invalid code. Please enter the correct 3-digit code");
        msg.exec();
    }
    else
        emit codeReceived(code);
}
