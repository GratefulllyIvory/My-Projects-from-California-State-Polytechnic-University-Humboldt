/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pass_by_ptr_display.h
 * Author: djbb1
 *
 * Created on September 11, 2020, 11:14 AM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

#ifndef PASS_BY_PTR_DISPLAY_H
#define PASS_BY_PTR_DISPLAY_H

void pass_by_ptr_display(int& intref);
void pass_by_ptr_display(double& doubleref);
void pass_by_ptr_display(char& charref);
void pass_by_ptr_display(bool& boolref);

#endif /* PASS_BY_PTR_DISPLAY_H */

