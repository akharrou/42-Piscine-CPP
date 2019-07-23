/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantPigTerminationForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 09:34:04 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTPIGTERMINATIONFORM_HPP
# define MUTANTPIGTERMINATIONFORM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AForm;
class MutantPigTerminationForm :
	public AForm {

	protected:
		MutantPigTerminationForm( void );

	public:
		MutantPigTerminationForm( std::string target );
		MutantPigTerminationForm( std::string target,
			const int signGradeReq, const int exeGradeReq );
		MutantPigTerminationForm( const MutantPigTerminationForm & src );
		~MutantPigTerminationForm( void );

		MutantPigTerminationForm &	operator = ( const MutantPigTerminationForm & rhs );

		void	action() const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MUTANTPIGTERMINATIONFORM_HPP */
