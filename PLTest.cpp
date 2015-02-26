#include<iostream>
using namespace std;

typedef char var;

/*----------------------LC-EXP SUPERCLASS----------------------*/

class LC_exp {
public:
  var identifier;
  var bound_var;

  // predicates
  bool var_exp_pred();
  bool lambda_exp_pred();
  bool app_exp_pred();

  // extractors
  var var_exp_var();
  var lambda_exp_bound_var();
  LC_exp lambda_exp_body();
  LC_exp app_exp_rator();
  LC_exp app_exp_rand();
  
  void print();

};

/*-------------------END LC-EXP SUPERCLASS--------------------*/

/*----------------------VAR-EXP SUBCLASS----------------------*/

class var_exp: public LC_exp {
public:
  // state variables
  var identifier;

  // constructor
  var_exp(var v);

  // predicates
  bool var_exp_pred();
  bool lambda_exp_pred();
  bool app_exp_pred();

  //extractor
  var var_exp_var();

  void print();

};
/*--------------------END VAR-EXP SUBCLASS--------------------*/

/*--------------------LAMBDA-EXP SUBCLASS---------------------*/

class lambda_exp: public LC_exp {
public:
  // state variables
  var bound_var;
  LC_exp body;

  // constructor
  lambda_exp(var param, LC_exp b);

  // predicates
  bool var_exp_pred();
  bool lambda_exp_pred();
  bool app_exp_pred();

  // extractors
  var lambda_exp_bound_var();
  LC_exp lambda_exp_body();

  void print_bound_var();
  void print_body(LC_exp e);

};

/*------------------END LAMBDA-EXP SUBCLASS-------------------*/

/*----------------------APP-EXP SUBCLASS----------------------*/

class app_exp: public LC_exp {
public:
  // state variables
  LC_exp rand;
  LC_exp rator;

  // constructor
  app_exp(LC_exp rand, LC_exp rator);

  // predicates
  bool var_exp_pred();
  bool lambda_exp_pred();
  bool app_exp_pred();

  // extractors
  LC_exp app_exp_rator();
  LC_exp app_exp_rand();

  void print_var_exp(var_exp e);
  void print_lambda_exp(lambda_exp e);
};


/*--------------------END APP-EXP SUBCLASS--------------------*/

/*------------------------CONSTRUCTORS------------------------*/

var_exp::var_exp(var v) {
  identifier = v;
}

lambda_exp::lambda_exp(var param, LC_exp b) {
  bound_var=param;
  body=b;
}

app_exp::app_exp(LC_exp r1, LC_exp r2) {
  rand = r1;
  rator = r2;
}

/*----------------------END CONSTRUCTORS----------------------*/

/*---------------------VAR-EXP PREDICATES---------------------*/

bool var_exp::var_exp_pred() {
  return true;
}

bool LC_exp::var_exp_pred() {
  return false;
}

bool app_exp::var_exp_pred() {
  return false;
}

/*-------------------END VAR-EXP PREDICATES-------------------*/

/*-------------------LAMBDA-EXP PREDICATES--------------------*/

bool lambda_exp::lambda_exp_pred() {
  return true;
}

bool var_exp::lambda_exp_pred() {
  return false;
}

bool app_exp::lambda_exp_pred() {
  return false;
}

/*-----------------END LAMBDA-EXP PREDICATES------------------*/

/*---------------------APP-EXP PREDICATES---------------------*/

bool app_exp::app_exp_pred() {
  return true;
}

bool lambda_exp::app_exp_pred() {
  return false;
}

bool var_exp::app_exp_pred() {
  return false;
}

/*-------------------END APP-EXP PREDICATES-------------------*/

/*---------------------VAR-EXP EXTRACTOR----------------------*/

var var_exp::var_exp_var() {
  return identifier;
}

/*-------------------END VAR-EXP EXTRACTOR--------------------*/

/*-------------------LAMBDA-EXP EXTRACTORS--------------------*/

var lambda_exp::lambda_exp_bound_var() {
  return bound_var;
}

LC_exp lambda_exp::lambda_exp_body() {
  return body;
}

/*-----------------END LAMBDA-EXP EXTRACTORS------------------*/

/*---------------------APP-EXP EXTRACTORS---------------------*/

LC_exp app_exp::app_exp_rand() {
  return rand;
}

LC_exp app_exp::app_exp_rator() {
  return rator;
}

/*-------------------END APP-EXP EXTRACTORS-------------------*/

/*-----------------------PRINT METHODS------------------------*/

void var_exp::print() {
  cout << "(lambda (" << this->identifier << "))" << endl;
}

void lambda_exp::print_bound_var() {
  cout << "(lambda (" << this->bound_var << "))";
}

void lambda_exp::print_body(LC_exp e) {
  cout << "(lambda (" << this->bound_var << "))" << endl;
}

void app_exp::print_var_exp(var_exp e) {
  cout << "(lambda ("  << e.identifier << "))";
}

void app_exp::print_lambda_exp(lambda_exp e) {
  cout << "(lambda (" << e.bound_var << ")) (lambda (" << e.bound_var << "))" << endl;
}

/*---------------------END PRINT METHODS----------------------*/

int main() {
  var test_var = 'y';
  var_exp e(test_var);
  lambda_exp le(test_var, e);
  app_exp ae(e, le);
  e.print();
  le.print_bound_var();
  le.print_body(e);
  ae.print_var_exp(e);
  ae.print_lambda_exp(le);
}

