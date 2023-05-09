/*
Ashdeep Singh 
CSCI 335 
Assignment 2
Date: 03/18/2022
File Name: sequende_map.h
Purpose: Implementation of SquenceMap class. Contained Big 5 along with other necessary memebr functions. 
*/

#ifndef SEQUENCE_MAP
#define SEQUENCE_MAP

#include<string>
#include<vector>
#include<iostream>
#include <sstream>

class SequenceMap{
public:
    //Default Copy Constructor
    SequenceMap(const SequenceMap & rhs) = default;
    //Default Move Constructor
    SequenceMap(SequenceMap && rhs) = default;
    //Default Copy Assignment Operator
    SequenceMap & operator= (const SequenceMap & rhs) = default;
    //Default Move Assignment Operator
    SequenceMap & operator= (SequenceMap && rhs) = default;
    //Default Destructor
    ~SequenceMap() = default;    

    /*
    Two Parameter Constructor:
    @pre
    @post: recognition_sequence_ is set to a_rec_seq; enzyme_acronyms_ is gains an_enz_acro
    @param
    */
    SequenceMap(const std::string &a_rec_seq, const std::string &an_enz_acro){
        this->enzyme_acronyms_.push_back(an_enz_acro);
        this->recognition_sequence_ = a_rec_seq;
    }

    /*
    Less Than Comparator:
    @pre: rhs is a pre-existing sequence map object
    @param: rhs- another pre-existing sequence map object
    @return true if current objects recognition_sequence_ is less than that of rhs'
    */
    bool operator<(const SequenceMap &rhs) const{
        return this->recognition_sequence_ < rhs.recognition_sequence_;
    }
    /*
    Greater Than Comparator:
    @pre: rhs is a pre-existing sequence map object
    @param: rhs- another pre-existing sequence map object
    @return true if current objects recognition_sequence_ is greater than that of rhs'
    */
    bool operator>(const SequenceMap &rhs) const{
        return this->recognition_sequence_ > rhs.recognition_sequence_;
    }

    /*
    Overloading the << operator:
    prints out all the enzyme acronym values in an pre-existing sequenceMap Object
    @pre: some_map is an existing sequeneMap object
    @param: out- reference to the out stream; some_map- a sequenceMap object whose entries will be displayed
    @post: elements in enzyme_acronyms_ have been displayed to the user
    */
    friend std::ostream &operator<<(std::ostream &out, SequenceMap &some_map){
        for(signed int i = 0; i < some_map.enzyme_acronyms_.size(); i++){
            out << some_map.enzyme_acronyms_[i];
            if(i != some_map.enzyme_acronyms_.size()-1){
                out << " ";
            }
        }
        return out; 
    }
    /*
    Overloading the >> operator:
    Read a chain from an input stream (e.g., standard input).
    allows the user to input values and fill in a pre-existing sequenceMap object with the values passed in
    @param: in- reference to the input stream; some_map- sequenceMap object to be updated with values passed through in-stream
    @post: sequenceMap has been filled with values passed through instream
    */
    friend std::istream &operator>>(std::istream &in, SequenceMap &some_map){
        std::string enz_acro;
        in >> some_map.recognition_sequence_;
        in >> enz_acro;
        some_map.enzyme_acronyms_.push_back(enz_acro);
        return in;
    } 

    /*
    Merge:
    merge current object with another sequenceMap object; current object iteration now also contains data of another object's enzyme_acronyms_
    @pre: other_sequence is a pre-existing sequenceMap object
    @post: current object iteration's enzyme_acronyms_ vector has been combined with that of other_sequences'
    @param: other_sequence- another sequenceMap object
    */
    void Merge(const SequenceMap &other_sequence){
        for(int i = 0; i < other_sequence.getEnzymeVector().size(); i++){
            this->enzyme_acronyms_.push_back(other_sequence.getEnzymeVector()[i]);
        }
    }

    /*
    recognition_sequence_ getter:
    @return recognition_sequence_
    */
    std::string getRecStr() const{
        return recognition_sequence_;
    }
    /*
    enzyme_acronyms_ getter:
    @return enzyme_acronyms_ elements in a string
    */
    std::string getEnzyme() const{   
        std::string ans = "";
        for(int i = 0; i < enzyme_acronyms_.size(); i++){
            ans += enzyme_acronyms_[i];
            if(i != enzyme_acronyms_.size()-1) ans+= " ";
        }
        return ans;
    }
    /*
    enzyme_acronyms_ getter:
    @return enzyme_acronyms_
    */
    std::vector<std::string> getEnzymeVector() const{
        return enzyme_acronyms_;
    }

private:
    std::string recognition_sequence_;
    std::vector<std::string> enzyme_acronyms_;
};

#endif

