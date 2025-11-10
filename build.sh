#!/bin/bash

pdflatex -shell-escape main.tex && evince main.pdf
