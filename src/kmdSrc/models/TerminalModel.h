/**
 * @file TerminalModel.h
 * @author Lawrence Warren (lawrencewarren2@gmail.com)
 * @brief The file containing the declaration of the class TerminalModel, which
 * represents all of the data and manipulation of the data associated with the
 * terminal view of the KoMo2 GUI.
 * @version 0.1
 * @date 2021-03-31
 * @section LICENSE
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 */

#include "RegistersModel.h"

class TerminalView;

/**
 * @brief Represents any data or functions related to the information, or
 * manipulation of the information, within the terminal view.
 */
class TerminalModel : private Model {
 public:
  TerminalModel(TerminalView* const view, KoMo2Model* const parent);
  void appendTextToTextView(std::string text);
  const std::string readJimulator() const;

  // ! Overriden virtual member functions

  virtual void changeJimulatorState(const JimulatorState newState) override;
  virtual const bool handleKeyPress(const GdkEventKey* const e) override;

  // ! Getters and setters

  TerminalView* const getView() const;

 private:
  /**
   * @brief The view this model represents.
   */
  TerminalView* const view;

  const bool isFocused();
  void onClearClick();

  // ! Deleted special member functions
  // stops these functions from being misused, creates a sensible error
  TerminalModel(const TerminalModel&) = delete;
  TerminalModel(const TerminalModel&&) = delete;
  TerminalModel& operator=(const TerminalModel&) = delete;
  TerminalModel& operator=(const TerminalModel&&) = delete;
};
