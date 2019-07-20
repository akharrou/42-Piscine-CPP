/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:47:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 16:50:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class ISpaceMarine {

	public:

		virtual ~ISpaceMarine() {}

		virtual ISpaceMarine	*clone       () const = 0;

		virtual void			battleCry    () const = 0;
		virtual void			rangedAttack () const = 0;
		virtual void			meleeAttack  () const = 0;

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* ISPACEMARINE_HPP */
