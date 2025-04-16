/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", S_REQUIRED_GRADE_SIGN, S_REQUIRED_GRADE_EXEC),
    _target("YourSon")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", S_REQUIRED_GRADE_SIGN, S_REQUIRED_GRADE_EXEC),
    _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

/* No tiene sentido poner esto son valores constantes y una vez inicializados no se pueden asignar
ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj) = delete; otra opcion*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& obj)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    (void)obj;
    return(*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return(_target);
}

/* Usa .c_str() cuando pases std::string a std::ofstream, ya que en C++98, ofstream no acepta directamente std::string.*/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > S_REQUIRED_GRADE_EXEC)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        std::string filename(this->getTarget());
        filename += "_shrubbery";
        try
        {
            std::ofstream outFile(filename.c_str());
            if (!outFile.is_open())
                throw std::runtime_error(" cant open");
            outFile << "       *" << std::endl;
            outFile << "      ***" << std::endl;
            outFile << "     *****" << std::endl;
            outFile << "    *******" << std::endl;
            outFile << "   *********" << std::endl;
            outFile << "  ***********" << std::endl;
            outFile << " *************" << std::endl;
            outFile << "***************" << std::endl;
            outFile << "       | |" << std::endl;
            outFile << "       | |" << std::endl;
            if (outFile.fail())
                throw std::runtime_error(" ,writing fail");
            outFile.close();
            if (outFile.fail())
                throw std::runtime_error(" ,close fail");
            std::cout << filename << " was sucefully created" << std::endl;
                
        }
        catch(std::exception& e)
        {
            std::cerr << "File " << filename << e.what()  << '\n';
        }
    }


    
}