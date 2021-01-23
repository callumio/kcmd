#include "RegistersView.h"
#include <iostream>
#include <sstream>
#include <string>
#include "../jimulatorInterface.h"

RegistersView::RegistersView(MainWindowView* parent) : grid(), parent(parent) {
  grid.set_column_homogeneous(false);
  grid.set_column_spacing(3);
  grid.set_row_spacing(3);

  // TODO: refactor this

  // Sets up each member of the array
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 16; j++) {
      // Set the left hand labels
      if (i == 0) {
        labelArray[i][j].set_size_request(70, 22);

        // First 0 through 14 are R registers
        if (j < 15) {
          labelArray[i][j].set_text("R" + std::to_string(j));
        }

        // final is the Program Counter
        else {
          labelArray[i][j].set_text("PC");
        }

      }

      // Right hand column
      else {
        labelArray[i][j].set_text("0x00000000");
        labelArray[i][j].set_size_request(120, 22);
        labelArray[i][j].set_xalign(0.1);
      }

      // Give each label styling and attach it to the grid

      labelArray[i][j].set_yalign(1);
      labelArray[i][j].get_style_context()->add_class("tableLabels");
      grid.attach(labelArray[i][j], i, j, 1, 1);
    }
  }

  // Adds and shows everything into the grid
  grid.get_style_context()->add_class("grid");
  pack_start(grid, true, true);
  show_all_children();
}

RegistersView::~RegistersView() {}

void RegistersView::setModel(RegistersModel* val) {
  model = val;
}

/**
 * @brief
 */
void RegistersView::refreshViews() {
  std::vector<std::string> v = getRegisterValueFromJimulator();

  // For each register in the array
  for (int i = 0; i < 16; i++) {
    labelArray[1][i].set_text(v[i]);
  }
}
