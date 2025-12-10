/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphore.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:35:37 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/10 00:16:44 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[]) {
  for (int idx = 0; idx < argc; ++idx) {
    std::cout << "argv[" << idx << "]=" << argv[idx] << "\n";
  }
  return (0);
}
