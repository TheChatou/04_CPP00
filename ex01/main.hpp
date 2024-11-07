/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:08:11 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/24 14:22:52 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>

// Text color
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

// Text style
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define UNDERLINE "\033[4m"
#define BLINK   "\033[5m"
#define REVERSE "\033[7m"
#define HIDDEN  "\033[8m"
#define ITALIC  "\033[3m"

// Background color
#define BG_BLACK   "\033[40m"      /* Black */
#define BG_RED     "\033[41m"      /* Red */
#define BG_GREEN   "\033[42m"      /* Green */
#define BG_YELLOW  "\033[43m"      /* Yellow */
#define BG_BLUE    "\033[44m"      /* Blue */
#define BG_MAGENTA "\033[45m"      /* Magenta */
#define BG_CYAN    "\033[46m"      /* Cyan */
#define BG_WHITE   "\033[47m"      /* White */

// else
#define SEPARATOR "-----------------------------------------------------"

#endif