/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:24:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 20:08:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_HPP
# define EVAL_EXPR_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# include <string>
# include <iostream>
# include <sstream>
# include "Fixed.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# define UNDERLINED(str) ("\033[4m" str "\033[0m")

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

Fixed		eval_expr           ( std::string expr, size_t & i );
Fixed		parseMultiplicative ( std::string expr, size_t & i );
Fixed		parseFixedNumber    ( std::string expr, size_t & i );
float		parseNumber         ( std::string expr, size_t & i );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

#endif /* EVAL_EXPR_HPP */
