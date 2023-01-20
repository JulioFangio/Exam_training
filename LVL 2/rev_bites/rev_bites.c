/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_bites.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:17:23 by juduval           #+#    #+#             */
/*   Updated: 2023/01/17 17:20:27 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char   rev_bits(unsigned char b)
{
    unsigned char   r;
    unsigned int    byte_len;

    r = 0;
    byte_len = 8;
    while (byte_len--)
    {
        r = (r << 1) | (b & 1);
        b >>= 1
    }
    retunr (r);
}