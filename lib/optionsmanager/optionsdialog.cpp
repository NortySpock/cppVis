#include "optionsdialog.h"
#include <QLineEdit>
#include <QComboBox>

namespace visualizer
{
  OptionsDialog::OptionsDialog()
    : QScrollArea( 0 )
  {
    show();
    setWindowTitle( "MegaMinerAI Visualizer Options" );
    setWidget( new QWidget( this ) );
    setWidgetResizable( true );
    setMinimumWidth( 500 );
    setMinimumHeight( 400 );
    widget()->show();

    QGridLayout *layout = new QGridLayout( widget() );
    widget()->setLayout( layout );

    size_t i = 0;
    for
      ( 
        map<string, Option >::iterator j = OptionsMan->m_options.begin(); 
        j != OptionsMan->m_options.end(); 
        j++ 
      )
    {
      layout->addWidget( new QLabel( j->second.key.c_str() ), i, 0 );
      switch( j->second.type )
      {
        case OP_INT:

          break;
        case OP_FLOAT:
        
          break;
        case OP_STRING:
        {
          QLineEdit *lineEdit = new QLineEdit( j->second.sValue.c_str() );
          layout->addWidget( lineEdit, i, 1 );
        }  break;
        case OP_COMBO:
        {
          QComboBox *comboBox = new QComboBox();
          layout->addWidget( comboBox, i, 1 );
          for
            ( 
            vector<string>::iterator k = j->second.sOptions.begin(); 
            k != j->second.sOptions.end();
            k++
            )
          {
            comboBox->addItem( k->c_str() );
            if( !k->compare( j->second.sValue ) )
              comboBox->setCurrentIndex( comboBox->count()-1 );
          }

        } break;
      }
      

      i++;
    }

    const int rowHeight = 30;

    widget()->setMinimumSize( 100, i*rowHeight );
    widget()->setMaximumHeight( i*rowHeight );

  }


} // visualizer
