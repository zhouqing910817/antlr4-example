#include "ExprBaseListener.h"
class SqlListener public ExprBaseListener {
public:

  virtual void enterStat(ExprParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(ExprParser::StatContext * /*ctx*/) override { }

  virtual void enterSelectSql(ExprParser::SelectSqlContext * /*ctx*/) override { }
  virtual void exitSelectSql(ExprParser::SelectSqlContext * /*ctx*/) override { }

  virtual void enterSelect(ExprParser::SelectContext * /*ctx*/) override { }
  virtual void exitSelect(ExprParser::SelectContext * /*ctx*/) override { }

  virtual void enterColumn(ExprParser::ColumnContext * /*ctx*/) override { }
  virtual void exitColumn(ExprParser::ColumnContext * /*ctx*/) override { }

  virtual void enterCol(ExprParser::ColContext * /*ctx*/) override { }
  virtual void exitCol(ExprParser::ColContext * /*ctx*/) override { }

  virtual void enterFrom(ExprParser::FromContext * /*ctx*/) override { }
  virtual void exitFrom(ExprParser::FromContext * /*ctx*/) override { }

  virtual void enterTable(ExprParser::TableContext * /*ctx*/) override { }
  virtual void exitTable(ExprParser::TableContext * /*ctx*/) override { }

  virtual void enterWhere(ExprParser::WhereContext * /*ctx*/) override { }
  virtual void exitWhere(ExprParser::WhereContext * /*ctx*/) override { }

  virtual void enterCondition(ExprParser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(ExprParser::ConditionContext * /*ctx*/) override { }

  virtual void enterOp(ExprParser::OpContext * /*ctx*/) override { }
  virtual void exitOp(ExprParser::OpContext * /*ctx*/) override { }

  virtual void enterValue(ExprParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(ExprParser::ValueContext * /*ctx*/) override { }

  virtual void enterNl(ExprParser::NlContext * /*ctx*/) override { }
  virtual void exitNl(ExprParser::NlContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};
