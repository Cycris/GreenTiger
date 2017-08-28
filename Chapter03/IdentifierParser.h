#pragma once
#include "ErrorHandler.h"
#include "Skipper.h"
#include <boost/spirit/include/qi.hpp>

namespace tiger {
template <typename Iterator>
class IdentifierParser
  : public boost::spirit::qi::grammar<Iterator, Skipper<Iterator>> {
public:
  IdentifierParser(ErrorHandler<Iterator> &errorHandler)
    : base_type(identifier) {
    namespace spirit = boost::spirit;
    namespace qi = spirit::qi;
    namespace ascii = spirit::ascii;

    using ascii::alnum;
    using ascii::alpha;

    using qi::lexeme;
    using qi::raw;

    keywords.add
    ("array")
      ("if")
      ("then")
      ("else")
      ("while")
      ("for")
      ("to")
      ("do")
      ("let")
      ("in")
      ("end")
      ("of")
      ("break")
      ("nil")
      ("function")
      ("var")
      ("type")
      ;

    identifier =
      !lexeme[keywords >> !(alnum | '_')]
      >> lexeme[alpha >> *(alnum | '_')]
      ;

    BOOST_SPIRIT_DEBUG_NODES(
      (identifier)
    )
  }

private:
  template <typename Signature = boost::spirit::qi::unused_type>
  using rule = boost::spirit::qi::rule<Iterator, Skipper<Iterator>, Signature>;
  template <typename... Types>
  using symbols = boost::spirit::qi::symbols<Types...>;

  rule<> identifier;

  symbols<char> keywords;
};
} // namespace tiger