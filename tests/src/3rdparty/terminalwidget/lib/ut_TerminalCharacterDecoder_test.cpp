/*
 *  Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd
 *
 * Author:     wangliang <wangliang@uniontech.com>
 *
 * Maintainer: wangliang <wangliang@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ut_TerminalCharacterDecoder_test.h"

//Qt单元测试相关头文件
#include <QTest>
#include <QtGui>
#include <QDebug>

UT_PlainTextDecoder_Test::UT_PlainTextDecoder_Test()
{
}

void UT_PlainTextDecoder_Test::SetUp()
{
}

void UT_PlainTextDecoder_Test::TearDown()
{
}

UT_HTMLDecoder_Test::UT_HTMLDecoder_Test()
{
}

void UT_HTMLDecoder_Test::SetUp()
{
}

void UT_HTMLDecoder_Test::TearDown()
{
}

#ifdef UT_CHARACTERCOLOR_TEST

/*******************************************************************************
 1. @函数:    PlainTextDecoder类的函数
 2. @作者:    ut000438 王亮
 3. @日期:    2020-12-28
 4. @说明:    decodeLine单元测试
*******************************************************************************/
TEST_F(UT_PlainTextDecoder_Test, decodeLine)
{
    const char aChar = 'c';
    Character aLineChar(aChar);

    QTextStream lineStream(new QString(aChar));
    PlainTextDecoder *decoder = new PlainTextDecoder;
    decoder->begin(&lineStream);
    EXPECT_NE(decoder->_output, nullptr);

    decoder->decodeLine(&aLineChar, 1, 0);
    EXPECT_EQ(decoder->_output->string()->length() > 0, true);

    decoder->end();
    EXPECT_EQ(decoder->_output, nullptr);

    delete decoder;
}

/*******************************************************************************
 1. @函数:    HTMLDecoder类的函数
 2. @作者:    ut000438 王亮
 3. @日期:    2020-12-28
 4. @说明:    decodeLine单元测试
*******************************************************************************/
TEST_F(UT_HTMLDecoder_Test, decodeLine)
{
    const char aChar = 'a';
    Character aLineChar(aChar);

    QTextStream htmlLineStream(new QString(aChar));
    HTMLDecoder *decoder = new HTMLDecoder;
    decoder->begin(&htmlLineStream);
    EXPECT_NE(decoder->_output, nullptr);

    decoder->decodeLine(&aLineChar, 1, 0);
    EXPECT_EQ(decoder->_output->string()->length() > 0, true);

    decoder->end();
    EXPECT_EQ(decoder->_output, nullptr);

    delete decoder;
}

#endif