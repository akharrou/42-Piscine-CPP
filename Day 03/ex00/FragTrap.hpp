/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 20:40:36 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

class FragTrap {

	public:

		FragTrap( void );
		FragTrap( /* regular */ );
		FragTrap( const FragTrap & src );
		~FragTrap( void );

		std::string		toString();
		FragTrap &			operator= (const FragTrap & rhs);

	private:

		/* attribs. */

};

std::ostream & operator<<( std::ostream & out, const FragTrap & in );

#endif /* FRAGTRAP_HPP */
