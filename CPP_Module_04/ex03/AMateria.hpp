class AMateria {
public:
    AMateria(const std::string& type);
    const std::string& getType() const;
    virtual Amateria* clone() const = 0;
    virtual void use(Icharacter& target);
protected:
};