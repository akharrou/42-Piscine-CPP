/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:24:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 16:32:16 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>

class Human {

	private:

		void	meleeAttack( std::string const & target );
		void	rangedAttack( std::string const & target );
		void	intimidatingShout( std::string const & target );

	public:

		void	action( std::string const & action_name, std::string const & target );

};

#endif /* HUMAN_HPP */
