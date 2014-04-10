#-------------------------------------------------
#
# Bechmark Test Case : Qt + Sqlite + In-memory
#
#-------------------------------------------------

QT += core
QT += sql
QT -= gui

TARGET = benchmark-sqllite-in-memory
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
