class AMateria {
public:
    AMateria();
    AMateria(const std::string& type);
    AMateria(const AMateria& obj);
    AMateria& operator=(const AMateria& obj);
    virtual ~AMateria();
    const std::string& getType() const;
    virtual Amateria* clone() const = 0;
    virtual void use(Icharacter& target);
protected:
    std::string type;
};
